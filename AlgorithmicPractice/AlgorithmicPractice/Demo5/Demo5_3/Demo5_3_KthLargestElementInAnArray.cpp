//
//  Demo5_3_KthLargestElementInAnArray.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo5_3_KthLargestElementInAnArray.hpp"


int findKthLargest(vector<int>& nums, int k) {
    return findKLargestElement(k, nums, 0, nums.size()-1);
}

int findKLargestElement(int k, vector<int>& nums, int low, int high) {
    int left = low;
    int right = high;
    int key = nums[left];
    while (left < right) {
        while (left < right && nums[right] < key) --right;
        nums[left] = nums[right];
        while (left < right && nums[left] >= key) ++left;
        nums[right] = nums[left];
    }
    nums[left] = key;
    if (left < (k-1)) {
        return findKLargestElement(k, nums, left+1, high);
    }
    else if (left > (k-1)) {
        return findKLargestElement(k, nums, low, left-1);
    }
    else {
        return key;
    }
}


