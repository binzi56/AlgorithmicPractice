//
//  Demo2_1_singleLinkedListFlip.hpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/28.
//  Copyright © 2018年 personal. All rights reserved.
//
//  链表翻转的图文讲解（递归与迭代两种实现）
//  https://blog.csdn.net/FX677588/article/details/72357389
//  Leetcode链表总结
//  https://blog.csdn.net/wonner_/article/details/79766037

#ifndef Demo2_1_singleLinkedListFlip_hpp
#define Demo2_1_singleLinkedListFlip_hpp

#include <stdio.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//迭代
ListNode* reverseList(ListNode* head);

//递归
ListNode* reverseList1(ListNode* head);

#endif /* Demo2_1_singleLinkedListFlip_hpp */
