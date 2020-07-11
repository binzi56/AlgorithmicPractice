//
//  Demo2_3_LinkedListCycle.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/19.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo2_3_LinkedListCycle.hpp"

// 思路：快慢指针 快慢指针相同则有环，证明：如果有环每走一步快慢指针距离会减1
bool hasCycle(ListNode *head) {
    if(head == NULL) return false;

    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        if(fast == slow) return true;
        fast = fast->next->next;
        slow = slow->next;
    }

    return false;
}
