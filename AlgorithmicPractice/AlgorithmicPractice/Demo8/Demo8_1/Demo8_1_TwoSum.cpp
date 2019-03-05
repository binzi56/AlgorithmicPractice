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
    map<int,int> m;
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
