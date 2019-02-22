//
//  Demo7_1_ClimbingStairs.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/22.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo7_1_ClimbingStairs.hpp"

int climbStairs(int n) {
    if (n <= 2) {
        return 2;
    }
    
    int fir = 1, sec = 2;
    for (int i = 2; i < n; i++) {
        int sum = fir + sec;
        fir = sec;
        sec = sum;
    }
    return sec;
}
