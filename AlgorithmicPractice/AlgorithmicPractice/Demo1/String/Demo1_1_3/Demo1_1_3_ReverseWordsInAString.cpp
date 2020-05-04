//
//  Demo1_1_3_ReverseWordsInAString.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/3/2.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo1_1_3_ReverseWordsInAString.hpp"


string reverseWords(string s) {
    // 反转整个字符串
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
        if (s[start] != ' ') {
            // 填一个空白字符然后将idx移动到下一个单词的开头位置
            if (idx != 0) s[idx++] = ' ';

            // 循环遍历至单词的末尾
            int end = start;
            while (end < n && s[end] != ' ') s[idx++] = s[end++];

            // 反转整个单词
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            // 更新start，去找下一个单词
            start = end;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}



string reverseWords2(string s) {
    vector<string> strs;
    string ans = "";
    string sub = "";
    for (int i = 0; i < s.size(); i++) {
       //到达空格
        if (s[i] == ' ') {
            //到达单词末尾
            if (sub.size() > 0) {
                strs.push_back(sub);
                sub = "";
            }
        }else{
            sub += s[i];
            if (i == s.size() - 1) strs.push_back(sub);
        }
    }

    for (int i = strs.size() - 1; i >= 0; i--) {
        ans += strs[i];
        if (i != 0) ans += " ";
    }
    return ans;
}
