#  正则表达式匹配

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
```
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
```
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:
```
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
```
示例 1:
```
输入:
s = "aa"
p = "a"
输出: false
```
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:
```
输入:
s = "aa"
p = "a*"
输出: true
```
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:
```
输入:
s = "ab"
p = ".*"
输出: true
```
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:
```
输入:
s = "aab"
p = "c*a*b"
输出: true
```
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:
```
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
```

解答:
```
//动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int m = s.size(),n = p.size();
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1,false));
        dp[0][0] = true;
        //先将p的可去开头找出来
        for(int j = 0;j < n;j++){
            if(p[j] == '*'){
                dp[0][j + 1] = dp[0][j - 1];
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(s[i] == p[j] || p[j] == '.'){
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if( p[j] == '*'){
                    //可忽略或p可多匹配
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] || (dp[i][j + 1] && (p[j - 1] == s[i] || p[j - 1] == '.'));
                }
                else{
                    dp[i + 1][j + 1] = false;
                }
            }
        }
        return dp[m][n];
    }
};

//递归(速度慢)
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.length()>1 && p[1]=='*')
            return isMatch(s,p.substr(2)) ||
                    (!s.empty() && (s[0]==p[0]||p[0]=='.') && isMatch(s.substr(1),p));
        else return !s.empty() && (s[0]==p[0]||p[0]=='.') &&
                    isMatch(s.substr(1),p.substr(1));
    }
};

```











附:
[动态规划解答](https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-de-li-jie-by-heifansy/)
[递归解答](https://leetcode-cn.com/problems/regular-expression-matching/solution/di-gui-dong-tai-gui-hua-by-joy-teng/)
