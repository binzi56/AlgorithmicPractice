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


int longestValidParentheses1(string s) {
    int maxLen = 0;
    vector<int> dp(s.length());
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {//倒数第二个
                dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
            }
        }
        maxLen = max(dp[i], maxLen);
    }
    return maxLen;
}


