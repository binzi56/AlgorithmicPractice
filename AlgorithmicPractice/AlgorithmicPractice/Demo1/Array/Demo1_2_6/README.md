#  搜索二维矩阵 II

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

* 每行的元素从左到右升序排列。
* 每列的元素从上到下升序排列。

示例:

现有矩阵 matrix 如下：
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```
给定 target = `5`，返回 `true`。

给定 target = `20`，返回 `false`。



解法:
```
//关键在于起点的选取，从左下角或者右上角开始
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i=matrix.size()-1,j=0;
    while(i>=0&&j<matrix[0].size())
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>target) i--;
        else j++;
    return false;
}
```
