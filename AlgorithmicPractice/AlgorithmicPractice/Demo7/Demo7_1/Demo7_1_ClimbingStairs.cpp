//
//  Demo7_1_ClimbingStairs.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/22.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo7_1_ClimbingStairs.hpp"

int climbStairs(int n){
     vector<int> dp(n+1);
     dp[0]=1;dp[1]=1;
     for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];  //动态转移方程
    return dp[n];
}

/*
 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 */

int numWays1(int n) {
     if(n < 2) return 1;
     vector<int> dp(n + 1);
     dp[0] = 1;
     dp[1] = 1;
     for(int i = 2; i <= n; i++){
         dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
     }

     return dp[n];
 }

