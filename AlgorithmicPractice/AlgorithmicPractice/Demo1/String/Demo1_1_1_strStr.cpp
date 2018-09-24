//
//  Demo1_1_1_strStr.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/24.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "Demo1_1_1_strStr.hpp"

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int m = haystack.size(), n = needle.size();
    if (m < n) return -1;
    for (int i = 0; i <= m - n; ++i) {
        int j = 0;
        for (j = 0; j < n; ++j) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
    }
    return -1;
}
