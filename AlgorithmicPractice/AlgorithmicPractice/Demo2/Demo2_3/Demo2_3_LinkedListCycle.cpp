//
//  Demo2_3_LinkedListCycle.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/19.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo2_3_LinkedListCycle.hpp"

bool hasCycle(ListNode *head) {
    ListNode* slowerNode = head;
    ListNode* fasterNode = head;
    
    while(slowerNode != NULL && fasterNode != NULL && fasterNode->next != NULL){
        slowerNode = slowerNode->next;
        fasterNode = fasterNode->next->next;
        
        if(slowerNode == fasterNode){
            return true;
        }
    }
    
    return false;
}
