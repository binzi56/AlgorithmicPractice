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
#include "Demo1_2_4_ThreeNumSum.hpp"
#include "Demo1_2_5_MajorityElement.hpp"
//Linked List
#include "Demo2/Demo2_1/Demo2_1_singleLinkedListFlip.hpp"
#include "Demo2/Demo2_2/Demo2_2_twoNumberAdd.hpp"
#include "Demo2/Demo2_3/Demo2_3_LinkedListCycle.hpp"
#include "Demo2/Demo2_4/Demo2_4_MergeTwoSortedLists.hpp"
#include "Demo2/Demo2_5/Demo2_5_deletListNNode.hpp"
#include "Demo2/Demo2_6/Demo2_6_middleNodeForList.hpp"

//Binary Tree
#include "Demo4_1_MaximumDepthOfBinaryTree.hpp"
#include "Demo4_2_InvertBinaryTree.hpp"
#include "Demo4_3_BalancedBinaryTree.hpp"
#include "Demo4_4_SymmetricTree.hpp"
#include "Demo4_5_SameTree.hpp"

//Sort
#include "Demo5/Demo5_1/Demo5_1_SortList.hpp"
#include "Demo5/Demo5_2/Demo5_2_sort.hpp"

//Search


//Dynamic programming
#include "Demo7_1_ClimbingStairs.hpp"

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
    
//1.2.4 三数之和
    vector<int> vecThree{-1, 0, 1, 2, -1, -4};
    printf("1.2.4 三数之和:\n");
    vector<vector<int>> vecFinal = threeSum(vecThree);
    printf("[\n");
    for (int i = 0; i < vecFinal.size(); i++) {
        vector<int> tempVec = vecFinal[i];
        printfIntArr(tempVec);
    }
    printf("[");
    
//
    
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
    
//2.3 环形链表
    ListNode *cycleList = createCycleList(2);
    bool isHas = hasCycle(cycleList);
    printf("2.3 环形链表:\n是否有环形链表---%d\n", isHas);
    
//2.4 合并两个有序链表
    int a1Arr[] = {1,2,4};
    int a1N = sizeof(a1Arr)/ sizeof(int);
    int a2Arr[] = {1,3,4};
    int a2N = sizeof(l2Arr)/ sizeof(int);
    ListNode *a1 = createLinkedList(a1Arr, a1N);
    ListNode *a2 = createLinkedList(a2Arr, a2N);
    
    ListNode *mergeList = mergeTwoLists(a1, a2);
    printf("2.4 合并两个有序链表:");
    printLinkedList(mergeList);
    
//2.5 删除链表的倒数第N个节点
    int a3Arr[] = {1,2,3,4,5};
    int a3N = sizeof(a3Arr)/ sizeof(int);
    ListNode *a3 = createLinkedList(a3Arr, a3N);
    
    ListNode *deleteList = removeNthFromEnd(a3, 2);
    printf("2.5 删除链表的倒数第N个节点:");
    printLinkedList(deleteList);
    
//2.6 链表的中间结点
    int a4Arr[] = {1,2,3,4,5,6};
    int a4N = sizeof(a4Arr)/ sizeof(int);
    ListNode *a4 = createLinkedList(a4Arr, a4N);
    
    ListNode *middleListNode = middleNode(a4);
    printf("2.6 链表的中间结点");
    printLinkedList(middleListNode);
    
    printf("\n\n#pragma mark - 三.栈和队列\n");
#pragma mark - 三.栈和队列
    
    printf("\n\n#pragma mark - 四.二叉树\n");
#pragma mark - 四.二叉树
    printf("\n\n#pragma mark - 五.排序\n");
#pragma mark - 五.排序
//5.1 排序链表
    int a5Arr[] = {4,2,1,3};
    int a5N = sizeof(a5Arr)/ sizeof(int);
    ListNode *a5 = createLinkedList(a5Arr, a5N);
    ListNode *sort5 = sortList(a5);
    printf("5.1 排序链表:");
    printLinkedList(sort5);
    
//5.2 排序算法集合
    printf("5.2 排序算法集合:");
    sortDemoTest();
    
    printf("\n\n#pragma mark - 六.搜索\n");
#pragma mark - 六.搜索
    
    printf("\n\n#pragma mark - 七.动态规划\n");
#pragma mark - 七.动态规划
//7.1 爬楼梯(斐波那契数列问题)
    int sumStairWay = climbStairs(3);
    printf("7.1 爬楼梯:\n%d", sumStairWay);
    
    printf("\n\n");
    return 0;
}


