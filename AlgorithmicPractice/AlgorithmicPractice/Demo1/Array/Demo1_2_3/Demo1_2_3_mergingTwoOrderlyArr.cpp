//
//  Demo1_2_3_mergingTwoOrderlyArr.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/27.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "Demo1_2_3_mergingTwoOrderlyArr.hpp"

//方法一
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            k--;
            i--;
            
        }else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
    
    //打印方法请忽略
    printfIntArr(nums1);
}

//方法二
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, index = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        nums1[index--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
    while (j >= 0)
    nums1[index--] = nums2[j--];
}
