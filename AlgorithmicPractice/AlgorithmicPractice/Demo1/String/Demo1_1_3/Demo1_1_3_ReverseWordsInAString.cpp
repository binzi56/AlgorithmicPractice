//
//  Demo1_1_3_ReverseWordsInAString.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/3/2.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo1_1_3_ReverseWordsInAString.hpp"


string reverseWords(string s) {
    int n = (int)s.size();
    int i = 0, j = 0;
    int start = 0;
    while(i < n){
        while(i < n && s[i] == ' ') i++;      //处理空格
        if(i < n && j > 0){                   //如果处理到非首单词(j>0)，要在其前加入空格
            s[j++] = ' ';
        }
        
        start = j;
        while(i < n && s[i] != ' '){
            s[j++] = s[i++];
        }
        reverse(s.begin() + start, s.begin() + j);
    }
    s.resize(j);                              //重置s大小
    reverse(s.begin(), s.end());              //翻转整个字符串
    return s;
}
