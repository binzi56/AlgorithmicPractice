#  Pow(x, n)


实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
```
输入: 2.00000, 10
输出: 1024.00000
```
示例 2:
```
输入: 2.10000, 3
输出: 9.26100
```
示例 3:
```
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```
说明:

* -100.0 < x < 100.0
* n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

解法:
```
//使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。还有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可。我们让i初始化为n，然后看i是否是2的倍数，是的话x乘以自己，否则res乘以x，i每次循环缩小一半，直到为0停止循环。最后看n的正负，如果为负，返回其倒数

double myPow(double x, int n) {
    double res = 1.0;
    for(int i = n; i != 0; i /= 2){
        if(i % 2 != 0){
            res *= x;
        }
        x *= x;
    }
    return  n < 0 ? 1 / res : res;
}

double myPow_1(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double cur = x;
    for (long long i = N; i != 0; i /= 2) {
        if ((i % 2) == 1) {
            ans = ans * cur;
        }
        cur = cur * cur;
    }
    return ans;
}

double myPow1(double x, int n) {
    double p = x;
    if (n < 0) p = 1/x;
    n = abs(n);
    double pow = 1;
    while (n > 0) {
        if (n & 1) {
            pow *= p;
        }

        n >>= 1;
        p *= p;
    }

    return pow;
}

double myPow2(double x, int n) {
    int t = n;
    double res = 1.0;
    while (n){
        if (n % 2){
            res *= x;
        }
        x *= x;
        n /= 2;
    }
    return t < 0 ? 1.0 / res : res;
}

double myPow3(double x, int n) {
    // 特殊情况处理
    if(n == 0) return 1;
    if(x == 0) return 0;
    double ans = 1;
    // 因为 n 为负时最小可达-2147483648，直接取反时超过int上限，因此特殊处理
    if(n < 0)
    {
        x = 1 / x;
        ans = x;
        n = -(n + 1);
    }
    // 快速幂
    while(n > 0)
    {
        if(n % 2 > 0) ans *= x;
        n /= 2;
        x = x * x;
    }
    return ans;
}

double myPow4(double x, int n) {
    if (n == 0) { return 1; }
    if (n == 1) { return x; }
    if (n == -1) { return 1 / x; }
    double half = myPow(x, n / 2);
    double rest = myPow(x, n % 2);
    return rest * half * half;
}

```
