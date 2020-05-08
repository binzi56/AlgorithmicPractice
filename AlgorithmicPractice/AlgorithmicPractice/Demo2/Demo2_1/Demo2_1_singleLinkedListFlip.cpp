
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
