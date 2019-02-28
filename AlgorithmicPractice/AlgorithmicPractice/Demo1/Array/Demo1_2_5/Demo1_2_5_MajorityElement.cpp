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
    int result = nums[0];
    int times = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (result == nums[i]) {
            times++;
        } else {
            times--;
            if (times == 0) {
                result = nums[++i];
                times++;
            }
        }
    }
    return result;
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
