#  斐波那契数

斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
给定 N，计算 F(N)。

 

示例 1：
```
输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
```
示例 2：
```
输入：3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
```
示例 3：
```
输入：4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
```

提示：

0 ≤ N ≤ 30


解法:
```
int fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}


int fib1(int N) {
int tmp=0;
vector<int> nums = {0,1};
if(N<2) return N;    
for(int i=2;i<=N;i++){
    tmp = nums[0] + nums[1];
    nums[0] = nums[1];
    nums[1] = tmp;
}
return tmp;
}

```

>  答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

```
int fib(int n) {
    if (n == 0) return 0;
    vector<int> dp (n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
}
```
