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
