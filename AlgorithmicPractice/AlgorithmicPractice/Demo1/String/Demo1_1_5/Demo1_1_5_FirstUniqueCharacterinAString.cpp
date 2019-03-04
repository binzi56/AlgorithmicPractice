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
