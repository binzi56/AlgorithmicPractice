//
//  Demo3_1_ValidParentheses.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo3_1_ValidParentheses.hpp"

 unordered_map<char, char> um = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
};

bool isValid(string s) {
    if (s.empty()) {
        return true;
    } else if (s.size() % 2) {
        return false;
    } else {
        stack<char> ss;
        for (int i = 0; i < s.size(); i++) {
            if (ss.empty()) {
                ss.push(s[i]);
            } else {
                if (s[i] == um[ss.top()]) {
                    ss.pop();
                } else {
                    ss.push(s[i]);
                }
            }
        }
        return ss.empty();
    }
}



bool isValid1(string s) {
    if(s.empty()) return true;
    
    unordered_map<char, int> m{
        {'(', -1},
        {'[', -2},
        {'{', -3},
        {')', 4},
        {']', 5},
        {'}', 6}
    };

    stack<char> st;
    for(char c: s) {
        if (m[c] < 0) st.push(c);
        else if (!st.empty() && m[st.top()] == -m[c]) st.pop();
        else return false;
    }
    return st.empty();
}


