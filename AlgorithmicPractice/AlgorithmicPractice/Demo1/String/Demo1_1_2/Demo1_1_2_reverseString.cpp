//
//  Demo1_1_2_reverseString.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/24.
//  Copyright © 2018年 personal. All rights reserved.
//


#include "Demo1_1_2_reverseString.hpp"

//双指针法
string reverseString(string s) {
    char temp;
    int begin = 0;
    int end = s.length() - 1;
    while(begin < end){
        temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
    return s;
}
