//
//  Demo6_1_Sqrt(x).cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/24.
//  Copyright © 2019 personal. All rights reserved.
//
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/shou-hui-man-hua-tu-jie-leetcodezhi-zai-pai-xu-shu/
//

#include "Demo6_1_Sqrt(x).hpp"

//二分法
int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 0, right = x;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x / mid >= mid) left = mid + 1;
        else right = mid;
    }
    return right - 1;
}
