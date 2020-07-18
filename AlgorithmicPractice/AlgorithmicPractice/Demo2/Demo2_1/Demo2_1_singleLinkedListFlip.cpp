
//
//  Demo2_1_singleLinkedListFlip.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/28.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "Demo2_1_singleLinkedListFlip.hpp"

//迭代
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL)
    {
        ListNode *lat = cur->next;
        cur->next = pre;
        pre = cur;
        cur = lat;
    }
    return pre;
}
 
//递归
ListNode* reverseList1(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }else{
        ListNode *h = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;
    }
}


/*
 两两交换链表中的节点
 给定 1->2->3->4, 你应该返回 2->1->4->3.
 */
//递归
ListNode* swapPairs(ListNode* head) {
    // 思路：将链表翻转转化为一个子问题，然后通过递归方式依次解决
    // 先翻转两个，然后将后面的节点继续这样翻转，然后将这些翻转后的节点连接起来
    return swap(head);
}

ListNode *swap(ListNode *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    // 保存下一阶段的头指针
    ListNode *nextNode = head->next->next;
    // 翻转当前阶段指针
    ListNode *curNode = head->next;
    curNode->next = head;
    head->next = swap(nextNode);
    return curNode;
}
