//
//  Demo1_2_5_MajorityElement.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo1_2_5_MajorityElement.hpp"



//解法一
int majorityElement(vector<int>& nums) {
    int count = 1;
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++){
          if(count == 0){
              ans = nums[i];
              count = 1;
          }else{
              if(nums[i] == ans){
                  count++;
              }else count--;
          }
    }
    return ans;
}

//解法二
int majorityElement1(vector<int>& nums) {
    int res = 0, cnt = 0;
    for (int num : nums) {
        if (cnt == 0) {res = num; ++cnt;}
        else (num == res) ? ++cnt : --cnt;
    }
    return res;
}

//解法三
int majorityElement2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

