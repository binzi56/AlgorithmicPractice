#  求1+2+…+n

求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。


示例 1：
```
输入: n = 3
输出: 6
```
示例 2：
```
输入: n = 9
输出: 45
```

限制：

* 1 <= n <= 10000


解答:
```
//递归
class Solution 1{
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};

//快速加
class Solution {
    int sum(int a, int n) {
        int ans = 0;
        (n > 0) && (ans = ans + sum(a << 1, n >> 1));
        (n & 1) && (ans = ans + a);
        return ans;
        /*  --以下非递归写法，上面递归写法
            --非递归写法必然用到while或者for，不符合题意，所以要使用递归写法
        int ans = 0;
        while(n) { 
            if (n & 1) {
                ans = ans + a;
            }
            a <<= 1; // 在快速幂中这里应该是a = a * a, 快速加应改成a = a + a
                     // 我用位运算优化了两数相加的操作
            n >>= 1;
        }
        return ans;
        */
    }
public:
    int sumNums(int n) {
        return sum(n + 1, n) >> 1;
    }
};
```
