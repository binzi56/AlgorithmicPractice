//
//  Demo3_3_EvaluateReversePolishNotation.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo3_3_EvaluateReversePolishNotation.hpp"

int evalRPN(vector<string>& tokens) {
    if (tokens.size() == 1) return stoi(tokens[0]);
    stack<int> st;
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
            st.push(stoi(tokens[i]));
        } else {
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            if (tokens[i] == "+") st.push(num2 + num1);
            if (tokens[i] == "-") st.push(num2 - num1);
            if (tokens[i] == "*") st.push(num2 * num1);
            if (tokens[i] == "/") st.push(num2 / num1);
        }
    }
    return st.top();
}
