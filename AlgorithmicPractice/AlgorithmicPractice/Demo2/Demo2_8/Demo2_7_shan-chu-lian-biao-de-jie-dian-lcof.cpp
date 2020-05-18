//
//  Demo2_7_shan-chu-lian-biao-de-jie-dian-lcof.cpp
//  AlgorithmicPractice
//
//  Created by shuaibin on 2020/5/18.
//  Copyright © 2020 personal. All rights reserved.
//

#include "Demo2_7_shan-chu-lian-biao-de-jie-dian-lcof.hpp"


ListNode* deleteNode(ListNode* head, int val) {
    if(head==NULL)return NULL;
    if(head->val==val)return head->next;
    ListNode *p=head;
    while(p->next){
        if(p->next->val==val){
            p->next=p->next->next;
            break;
        }
        p=p->next;
    }
    return head;
}
