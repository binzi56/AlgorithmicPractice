//
//  Demo2_6_middleNodeForList.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/23.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo2_6_middleNodeForList.hpp"

ListNode* middleNode(ListNode* head) {
    ListNode*cur=head->next;
    ListNode*prev=head;
    while(cur != NULL)
    {
        if(cur->next != NULL)
        {
            cur=cur->next->next;
        }
        else
        {
            cur=cur->next;
        }
        prev=prev->next;
    }
    return prev;
}
