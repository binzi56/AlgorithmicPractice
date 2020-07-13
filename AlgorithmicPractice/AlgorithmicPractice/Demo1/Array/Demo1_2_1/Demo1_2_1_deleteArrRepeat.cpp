//
//  Demo1_2_1_deleteArrRepeat.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/24.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "Demo1_2_1_deleteArrRepeat.hpp"

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int k = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[k] != nums[i]){
            k++;
            nums[k] = nums[i];
        }
    }

    return ++k;
}


