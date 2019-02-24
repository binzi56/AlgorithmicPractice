//
//  Demo3_2_LongestValidParentheses.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo3_2_LongestValidParentheses.hpp"

int longestValidParentheses(string s) {
    int res = 0, start = 0;
    stack<int> m;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') m.push(i);
        else if (s[i] == ')') {
            if (m.empty()) start = i + 1;
            else {
                m.pop();
                res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
            }
        }
    }
    return res;
}
