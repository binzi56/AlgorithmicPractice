//
//  Demo3_1_ValidParentheses.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo3_1_ValidParentheses.hpp"

bool isValid(string s) {
  if(s.empty()) return false;
  if(s.size() % 2) return false;

  unordered_map<char, char> m = {
      {'{', '}'},
      {'[',']'},
      {'(',')'}
  };

  stack<char> st;
  for(char temp : s){
      if(st.empty()){
           st.push(temp);
      }else{
           if(temp == m[st.top()]){
              st.pop();
           }else{
              st.push(temp);
           }
      }
  }

  return st.empty();

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


