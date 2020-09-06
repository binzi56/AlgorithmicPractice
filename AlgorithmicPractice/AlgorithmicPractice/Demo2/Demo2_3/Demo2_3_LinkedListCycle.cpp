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

/* 找到第一个入环点 */
// 思路：快慢指针，快慢相遇之后，慢指针回到头，快慢指针步调一致一起移动，相遇点即为入环点
ListNode *detectCycle(ListNode *head) {
    if(head == NULL) return head;

    ListNode *fast = head->next;
    ListNode *slow = head;
    while(fast != NULL && fast->next != NULL){
        if(fast == slow){ // 第一次相遇，slow回到head, fast从相遇点下一个节点开始走
            slow = head;
            fast = fast->next;
            while(fast != slow){ // 第二次相遇的地方就是环的入口
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }

        fast = fast->next->next;
        slow = slow->next;
    }

    return NULL;
}
