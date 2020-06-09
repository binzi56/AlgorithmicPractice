#  整数拆分

给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:
```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
```
示例 2:
```
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
```
说明: 你可以假设 n 不小于 2 且不大于 58。

解答:
```
class Solution 1{
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);//存储为n时的乘积最大化
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(max(dp[i - j] * dp[j], dp[j] * (i - j)), max(dp[i - j] * j, (i - j) * j)));
            }
        }
        return dp[n];
    }
};

//关键一步 dp[i]由四种状态组成 
//1.拆j数字分成小块整数拆分求最大 i - j不拆开 就是dp[j] * (i - j)
//2.拆i - j这个数字整数拆分求最大j不拆开就是dp[i - j] * j
//3.两个都整数拆分分别求最大就是 dp[i - j] * dp[j]
//4. i和i - j都不整数拆分 就是i * (i - j)
//然后四个求出最大值

//贪心
class Solution 2{
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;  //必须切一刀
        //n >= 5 2*(n-2) > n   3*(n-3) > n  且3*(n-3) >= 2*(n-2)
        //n = 4 2 * 2 > 1 * 3
        //2和3不能再分了  分了就变小了 且3优于2
        int a = n / 3;
        int b = n % 3;
        if(b == 0){
            //全部分成3
            return pow(3, a);
        }
        if(b == 1){
            //n = 10 3 * 3 * 3 * 1 ==> 3 * 3 * 2 * 2
            //4   1 和 3 要变成2 * 2
            return pow(3, a-1) * 4;
        }
        //b == 2  2不能再分了
        return pow(3, a) * 2;
    }
};
```


> 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

解法:
```

class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int mod = 1000000007;
        long long res = 1;
        while(n>4){
            res*=3;
            res%=mod;
            n-=3;
        }
        res = res*n%mod;
        return res;
    }
};
```
