#  无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```
示例 2:
```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
示例 3:
```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```







解法:

```
//滑动窗口
//解法一：
int lengthOfLongestSubstring(string s) {
    if(s.empty()) return 0;
    vector<int> map(128, -1);           //int map[128] = {-1}会出错;这只让第一个值为-1，其余的还是为0
    int len = 0,start = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(map[s[i]] >= start)          //大于等于start，表示s[i]在本段子串中出现过
            start = map[s[i]] + 1;     //map[s[i]]记录上次出现本字符的位置，+1更新start为新的子串起始位置
        map[s[i]] = i;               
        len = max(len,i - start + 1);
    }
    return len;
}

//解法二：
int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        // 滑动窗口核心点：1、右指针右移 2、根据题意收缩窗口 3、左指针右移更新窗口 4、根据题意计算结果
        unordered_map<char,int> window;
        
        int left = 0, right = 0, ans = 1;
        while(right < s.size()){
            char c = s[right];
            right++;
            window[c]++;
            
            // 缩小窗口
            while(window[c] > 1){
                char d = s[left];
                left++;
                window[d]--;
            }
            // 计算结果
            ans = max(ans, right - left);
        }

        return ans;
}
```
