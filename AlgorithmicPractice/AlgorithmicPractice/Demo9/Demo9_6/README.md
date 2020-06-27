#  机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：
```
输入：m = 2, n = 3, k = 1
输出：3
```
示例 2：
```
输入：m = 3, n = 1, k = 0
输出：1
```
提示：

* 1 <= n,m <= 100
* 0 <= k <= 20


解法:
```
//由已知条件知道，m,n 都是在1-100之间，也就是最大数组位置也是两位数，即（99，99），因此判断位数和可以表示如下：
i%10 + i/10 + j%10 + j/10 > k

class Solution {
public:
    int nums = 0;
    int movingCount(int m, int n, int k) {
        vector<vector <int> > arr(m, vector<int>(n, 0));
        if(k == 0)
            return 1;
        search(m, n, k, arr, 0, 0);
        return nums;
    }
    void search(int m, int n, int k, vector<vector <int> >& arr, int i, int j){
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
        if(arr[i][j] == 1)
            return;
        if((i%10 + i/10 + j%10 + j/10) > k)
            return;
        arr[i][j] = 1;
        nums++;
        search(m, n, k, arr, i-1, j);
        search(m, n, k, arr, i+1, j);
        search(m, n, k, arr, i, j-1);
        search(m, n, k, arr, i, j+1);
    }
};
```

