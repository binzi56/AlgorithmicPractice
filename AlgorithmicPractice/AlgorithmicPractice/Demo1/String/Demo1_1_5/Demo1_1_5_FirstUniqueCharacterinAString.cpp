//
//  Demo1_1_5_FirstUniqueCharacterinAString.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/3/4.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo1_1_5_FirstUniqueCharacterinAString.hpp"


int firstUniqChar(string s) {
    int n = (int)s.size();
    if (n == 1) return 0;
    if (n == 0) return -1;
    
    int flag = 0;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] == s[j] && i != j) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    
    return -1;
}


int firstUniqChar1(string s) {
    int hash[26]={0};
    for(char n:s)
        hash[n-'a']++;          //n-'a'，得到该字母在数组中对应的索引
    for(int i=0;i<s.size();i++)
        if(hash[s[i]-'a']==1)       //如果只出现了一次
            return i;
    return -1;
}


int firstUniqChar3(string s) {
     //如果该字符第一次出现的位置和最后一次出现的位置一样，就证明不重复
     for(int i = 0; i < s.size(); i++){
         if(s.find(s[i]) == s.rfind(s[i])) return i;
     }
     return -1;
}
