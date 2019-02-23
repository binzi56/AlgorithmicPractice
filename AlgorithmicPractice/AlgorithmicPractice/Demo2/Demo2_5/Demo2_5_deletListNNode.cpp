//
//  Demo2_5_deletListNNode.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/23.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo2_5_deletListNNode.hpp"


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *right = head;
    ListNode *left = head;
    for (int i = 0; i < n; i++) {
        right = right->next;
    }
    
    //right->val == 3
    
    if (right == NULL) {
        head = head->next;
        return head;
    }
    while (right->next != NULL) {
        left = left->next;
        right = right->next;
    }
    
    //left->next->val == 4;
    left->next = left->next->next;
    return head;
}
