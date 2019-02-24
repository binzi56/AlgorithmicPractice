//
//  Demo3_1_ValidParentheses.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo3_1_ValidParentheses.hpp"

bool isValid(string s) {
    stack<char> parentheses;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
        else {
            if (parentheses.empty()) return false;
            if (s[i] == ')' && parentheses.top() != '(') return false;
            if (s[i] == ']' && parentheses.top() != '[') return false;
            if (s[i] == '}' && parentheses.top() != '{') return false;
            parentheses.pop();
        }
    }
    return parentheses.empty();
}


bool isValid1(string s) {
    stack<char> paren;
    for (char& c : s) {
        switch (c) {
            case '(':
            case '{':
            case '[': paren.push(c); break;
            case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
            case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
            case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
            default: ;
        }
    }
    return paren.empty() ;
}
