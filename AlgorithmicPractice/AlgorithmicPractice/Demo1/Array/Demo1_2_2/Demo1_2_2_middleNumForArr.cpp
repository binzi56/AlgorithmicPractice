//
//  Demo1_2_2_middleNumForArr.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/26.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "Demo1_2_2_middleNumForArr.hpp"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> numsAll;
    
    for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();) {
        if (i < nums1.size()) {
            if (j < nums2.size()) {
                if (nums1[i] < nums2[j]) {
                    numsAll.push_back(nums1[i++]);
                } else {
                    numsAll.push_back(nums2[j++]);
                }
            } else {
                numsAll.push_back(nums1[i++]);
            }
        } else {
            numsAll.push_back(nums2[j++]);
        }
    }
    
    long middle = (nums1.size() + nums2.size()) >> 1;
    if ((nums1.size() + nums2.size()) % 2 == 1) {
        return (double)numsAll[middle];
    } else {
        return ((double)numsAll[middle] + (double)numsAll[middle-1]) / 2.0;
    }
    
}
