#  把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。


示例 1:
```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

提示：

* 0 <= num < 2^31

解法:
```
//回溯
class Solution 1{
public:
    int backtrace(string& str, int pos) {
        int n = str.size();
        if (pos == n) {
            return 1;
        }
        if (pos == n-1 || str[pos] == '0' || str.substr(pos, 2) > "25") {
            return backtrace(str, pos+1);
        }
        return backtrace(str, pos+1) + backtrace(str, pos+2);
    }
    int translateNum(int num) {
        string str = to_string(num);
        return backtrace(str, 0);
    }
};

//动态规划
class Solution 2{
public:
    int translateNum(int num) {
        string str = to_string(num);
        int dp[11];  //num 最大为 2^31，所以它的长度不会超过 11
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < str.size(); i ++) {
            if (str[i-1] == '0' || str.substr(i-1, 2) > "25" ) {  //小写字母就26个，0~25正好可以表示它们
                dp[i+1] = dp[i];   //不能合成一个字符
            } else {
                dp[i+1] = dp[i] + dp[i-1];  //能够合成一个字符
            }
        }
        return dp[str.size()];
    }
};

```



[把数字翻译成字符串：回溯，动态规划](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-hui-su-dong-tai/)
