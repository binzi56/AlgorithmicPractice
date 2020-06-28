#  数字 1 的个数

给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例:
```
输入: 13
输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
```

解释:
```
class Solution 1{
public:
    int countDigitOne(int n) {
        if(n == 0){
            return 0;
        }
        int result = 0;
        int lowerNum = 0,curNum = 0,highNum = 0;
        int base = 1;
        int num = n;
        while(num){
            lowerNum = n - num * base;  // 低位部分
            curNum = num % 10;          // 当前部分
            highNum = num / 10;         // 高位部分

            if(curNum == 0){
                // 如果为0则这一位1出现的次数由更高位决定 (更高位数字*当前位数)      
                result += highNum * base;
            }else if(curNum == 1){
                // 如果为1则这一位1出现的次数不仅受更高位影响还受低位影响(更高位数字*当前位数+低位数字+1)
                result += highNum * base + (lowerNum + 1);
            }else{
                // 大于1则仅受更高位影响((更高位数字+1)*当前位数)
                result += (highNum + 1) * base;
            }
            num /= 10;
            base *= 10;
        }
        return result;
    }
};

class Solution 2{
public:
    int countDigitOne(int n) {
        if(n < 0) return 0;
        int ans = 0;
        int left, right = 0, idx = 0, cur = 0;
        while(n){
            cur = n % 10;
            left = n/10; 
            if(cur == 0){
                ans += left*pow(10, idx);
            }else if(cur == 1){
                ans += left*pow(10, idx) + right + 1;
            }else{
                ans += (left + 1)*pow(10, idx);
            }
            right += cur*pow(10, idx);
            n /= 10;
            idx++;
        }
        return ans;
    }
};

class Solution 2{
    int countDigitOne(int n) {
        if (n < 1)
            return 0;
        int len = getLenOfNum(n);
        if (len == 1)
            return 1;
        int tmp = (int) pow(10, len - 1);
        int first = n / tmp; // 获取n的最高位数字
        int firstOneNum = first == 1 ? n % tmp + 1 : tmp; // 获取n的最高位为1时有多少个数字
        int otherOneNUm = first * (len - 1) * (tmp / 10); // 在介于n % tmp到n之间的数字中，除了最高位为1，其余各个数字分别为1 的总数和
        return firstOneNum + otherOneNUm + countDigitOne(n % tmp);
    }
    int getLenOfNum(int n) {
        int len = 0;
        while (n != 0) {
            len++;
            n /= 10;
        }
        return len;
    }
}
```

[C++ 对每位进行分析](https://leetcode-cn.com/problems/number-of-digit-one/solution/c-dui-mei-wei-jin-xing-fen-xi-by-yizhe-shi-2/)
