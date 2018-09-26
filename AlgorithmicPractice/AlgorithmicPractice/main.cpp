//
//  main.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/22.
//  Copyright © 2018年 personal. All rights reserved.
//

#include <iostream>
//工具类
#include "CommonTools.hpp"
//Demo相关类
#include "Demo1_1_1_strStr.hpp"
#include "Demo1_1_2_reverseString.hpp"
#include "Demo1_2_1_deleteArrRepeat.hpp"

int main(int argc, const char * argv[]) {
    
#pragma mark - 一.基础数据结构
#pragma mark - 1.1 字符串
//1.1.1 实现strStr()函数
    printf("1.1.1 实现strStr()函数:\n%d\n", strStr("aaaaa", "bba"));
//1.1.2 反转字符串
    printf("1.1.2 反转字符串:\n%s\n", reverseString("A man, a plan, a canal: Panama").c_str());
    
#pragma mark - 1.2 数组
//1.2.1 删除排序数组中的重复项
    vector<int> vecArr{0,0,1,1,1,2,2,3,3,4};
    printf("1.2.1 删除排序数组中的重复项:\n%d\n", removeDuplicates(vecArr));

#pragma mark - 二.链表
                         
#pragma mark - 三.栈和队列
   
    
#pragma mark - 四.二叉树
                         
#pragma mark - 五.排序
                         
#pragma mark - 六.搜索
                         
#pragma mark - 七.动态规划

    printf("\n");
    return 0;
}


