//
//  Demo2_4_MergeTwoSortedLists.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo2_4_MergeTwoSortedLists.hpp"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL){
        return l2;
    }else if(l2 == NULL){
        return l1;
    }
    
    ListNode *allNode = NULL;
    
    if(l1->val < l2->val){
        allNode = l1;
        allNode->next = mergeTwoLists(allNode->next,l2);
    }else{
        allNode = l2;
        allNode->next = mergeTwoLists(l1, allNode->next);
    }
    return allNode;
}
