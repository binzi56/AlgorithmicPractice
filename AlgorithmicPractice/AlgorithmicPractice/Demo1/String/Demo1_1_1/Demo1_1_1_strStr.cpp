//
//  Demo1_1_1_strStr.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/24.
//  Copyright © 2018年 personal. All rights reserved.
//
/*
 C:
 str长度
 length == sizeof(str) / sizeof(str[0])
 */

#include "Demo1_1_1_strStr.hpp"

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int haystackSize = haystack.size(), needleSize = needle.size();
    if (haystackSize < needleSize) return -1;
    for (int i = 0; i <= haystackSize - needleSize; ++i) {
        int j = 0;
        for (j = 0; j < needleSize; ++j) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == needleSize) return i;
    }
    return -1;
}
