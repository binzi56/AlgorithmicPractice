//
//  Demo5_3_KthLargestElementInAnArray.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo5_3_KthLargestElementInAnArray.hpp"


int findKthLargest(vector<int>& nums, int k) {
    int length = (int)nums.size();
    return findKLargestElement(k, nums, 0, length-1);
}

int findKLargestElement(int k, vector<int>& nums, int low, int high){
    int first = low;
    int last = high;
    int key = nums[first];

    while (first < last) {
        while (first < last && nums[last] <= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] >= key) {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;

    if (first < k - 1) {
        return findKLargestElement(k, nums, first + 1, high);
    }else if (first > k - 1){
        return findKLargestElement(k, nums, low, first - 1);
    }else{
        return key;
    }
}

