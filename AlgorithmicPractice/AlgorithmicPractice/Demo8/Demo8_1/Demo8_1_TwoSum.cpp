//
//  Demo8_1_TwoSum.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/3/5.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo8_1_TwoSum.hpp"


vector<int> twoSum(vector<int> nums,int target){
    vector<int> res;
    unordered_map<int, int> m;
    for(int i=0;i<nums.size();i++)
    {
        if(m.find(target-nums[i]) != m.end())
        {
            res.push_back(m[target-nums[i]]);
            res.push_back(i);
        }
        m[nums[i]] = i;
    }
    return res;
}


vector<int> twoSum1(vector<int>& nums, int target) {
   vector<int> res;
   if(nums.empty()) return res;

   for(int i = 0; i < nums.size(); i++){
      for(int j = i + 1; j < nums.size(); j++){
          if(nums[i] + nums[j] == target){
              res.push_back(i);
              res.push_back(j);
              break;
          }
      }
   }

   return res;
}
