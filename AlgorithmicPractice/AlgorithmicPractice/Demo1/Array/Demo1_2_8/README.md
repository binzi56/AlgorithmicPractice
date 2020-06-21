#  螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:
```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5] 
```
示例 2:
```
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```

解答:
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int upper = 0, downer = matrix.size() - 1;  // 设置上下边界
        int left = 0, right = matrix[0].size() - 1; //设置左右边界
        while (upper <= downer && left <= right) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[upper][i]);
            }
            upper++;    //上边界往下一行
            if (upper > downer) {       //若此时条件不满足，则已遍历完成
                break;
            }
            for (int i = upper; i <= downer; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;    //右边界往左一列
            if (left > right) {     //若此时条件不满足，则已遍历完成
                break;
            }
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[downer][i]);
            }
            downer--;   //下边界往上一行
            for (int i = downer; i >= upper; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;     //左边界往右一列
        }
        
        return result;
    }
};
```
