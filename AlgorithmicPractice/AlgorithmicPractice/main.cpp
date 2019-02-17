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
//string
#include "Demo1_1_1_strStr.hpp"
#include "Demo1_1_2_reverseString.hpp"
//array
#include "Demo1_2_1_deleteArrRepeat.hpp"
#include "Demo1_2_2_middleNumForArr.hpp"
#include "Demo1_2_3_mergingTwoOrderlyArr.hpp"
//Linked List
#include "Demo2/Demo2_1/Demo2_1_singleLinkedListFlip.hpp"
#include "Demo2/Demo2_2/Demo2_2_twoNumberAdd.hpp"
int main(int argc, const char * argv[]) {
    
    printf("\n#pragma mark - 一.基础数据结构\n");
#pragma mark - 一.基础数据结构
    printf("\n#pragma mark - 1.1 字符串\n");
#pragma mark - 1.1 字符串
//1.1.1 实现strStr()函数
    printf("1.1.1 实现strStr()函数:\n%d\n", strStr("aaaaa", "bba"));
//1.1.2 反转字符串
    printf("1.1.2 反转字符串:\n%s\n", reverseString("A man, a plan, a canal: Panama").c_str());
    
    printf("\n#pragma mark - 1.2 数组\n");
#pragma mark - 1.2 数组
//1.2.1 删除排序数组中的重复项
    vector<int> vecArr{0,0,1,1,1,2,2,3,3,4};
    printf("1.2.1 删除排序数组中的重复项:\n%d\n", removeDuplicates(vecArr));
//1.2.2 两个排序数组的中位数
    vector<int> vecArr1{1, 2};
    vector<int> vecArr2{3, 4};
    printf("1.2.2 两个排序数组的中位数:\n%f\n", findMedianSortedArrays(vecArr1, vecArr2));
//1.2.3 合并两个有序数组
    vector<int> vecArr3{1,2,3,0,0,0};
    vector<int> vecArr4{2,5,6};
    printf("1.2.3 合并两个有序数组:\n");
    merge(vecArr3, 3, vecArr4, 3);
    
    printf("\n\n#pragma mark - 二.链表\n");
#pragma mark - 二.链表
//2.1 反转链表(单链表)
    int reverteArr[] = {1,2,3,4,5};
    int reverteN = sizeof(reverteArr)/ sizeof(int);
    ListNode *reList = createLinkedList(reverteArr, reverteN);
    ListNode *reverteList = reverseList(reList);
    printf("2.1 反转链表(单链表):");
    printLinkedList(reverteList);

//2.2 两数相加
    int l1Arr[] = {2,4,3};
    int l1N = sizeof(l1Arr)/ sizeof(int);
    int l2Arr[] = {5,6,4};
    int l2N = sizeof(l2Arr)/ sizeof(int);
    ListNode *l1 = createLinkedList(l1Arr, l1N);
    ListNode *l2 = createLinkedList(l2Arr, l2N);
    
    ListNode *resultList = addTwoNumbers(l1, l2);
    printf("2.2 两数相加:");
    printLinkedList(resultList);
    
#pragma mark - 三.栈和队列
   
    
#pragma mark - 四.二叉树
                         
#pragma mark - 五.排序
                         
#pragma mark - 六.搜索
                         
#pragma mark - 七.动态规划

    printf("\n");
    return 0;
}


