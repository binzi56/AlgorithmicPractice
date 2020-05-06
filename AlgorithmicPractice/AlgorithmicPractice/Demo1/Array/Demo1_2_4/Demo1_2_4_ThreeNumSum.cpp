//
//  Demo1_2_7_ThreeNumSum.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo1_2_4_ThreeNumSum.hpp"

vector<vector<int>> threeSum(vector<int>& nums) {
   vector<vector<int>> ans;
   int numsSize = nums.size();
   if(numsSize < 3) return ans;
   sort(nums.begin(), nums.end());
   for(int i = 0; i < numsSize - 2; i++){
       if(nums[i] > 0) break; //如果当前数字大于0，则三数之和一定大于0，所以结束循环
       if(i > 0 && nums[i] == nums[i - 1]) continue; //去重
       int j = i + 1, k = numsSize - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j < k && nums[j] == nums[j+1]) j++; //去重
                while(j < k && nums[k] == nums[k-1]) k--; //去重
                j++;
                k--;
            }
            else if(sum < 0) j++;
            else k--;
        }
   }

   return ans;
}
