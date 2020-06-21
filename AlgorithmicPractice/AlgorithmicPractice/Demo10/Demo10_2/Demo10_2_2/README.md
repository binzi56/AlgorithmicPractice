#  第N个数字

在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

注意:
n 是正数且在32位整数范围内 ( n < 231)。

示例 1:
```
输入:
3

输出:
3
```
示例 2:
```
输入:
11

输出:
0
```
说明:
第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

解法:
```
class Solution {
public:
    int findNthDigit(int n) {
        // bit记录所在区间的位数，p记录所在区间的长度
        long long bit = 1, p = 9;
        while(n - bit * p > 0){
            n -= p * bit;
            bit++;
            p *= 10;
        }

        // num是答案所在数字
        int num = pow(10, bit - 1) + (n-1) / bit;

        // pos是答案在num中的位数(从左向右数)
        int pos = n % bit;
        pos = pos == 0 ? bit : pos;

        int t = pow(10, bit - pos);
        return num / t % 10;
    }
};
```
