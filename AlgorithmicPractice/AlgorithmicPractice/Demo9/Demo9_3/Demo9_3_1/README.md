#  字符串的排列


输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:
```
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
```

限制：

> 1 <= s 的长度 <= 8





解法:
```
class Solution {
public:
    vector<string>res;
    vector<string> permutation(string s) {
        int cursor=0;
        permutation(s,cursor);
        return res;
    }
    void permutation(string &s,int cursor){
        if(cursor==s.size()-1){
            res.push_back(s);
        }
        else{
            for(int i=cursor;i<s.size();i++){
                if(judge(s,cursor,i))continue;  //从cursor开始，遍历不重复的字符
                swap(s[cursor],s[i]);
                permutation(s,cursor+1);
                swap(s[cursor],s[i]);
            }
        }
    }
    bool judge(string& s, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (s[i] == s[end]) return true;
        }
        return false;
    }
};

```
