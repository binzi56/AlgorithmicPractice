//
//  Demo2_2_twoNumberAdd.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/17.
//  Copyright © 2019年 personal. All rights reserved.
//

#include "Demo2_2_twoNumberAdd.hpp"

//解法一:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0), *r=head;
    int up = 0;
    while (l1!= NULL || l2!= NULL ||up ) {
        r->next=new ListNode(((l1==NULL?0:l1->val) + (l2==NULL?0:l2->val) + up) % 10);
        up = ((l1==NULL ? 0 : l1->val) + (l2==NULL ? 0 : l2->val) + up) / 10;
        r = r->next;
        if(l1!=NULL)        l1 = l1->next;
        if (l2!=NULL)        l2 = l2->next;
    }
    return head->next;
};

//解法二:
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    ListNode *p=new ListNode(-1);
    ListNode *q=p;
    int carry=0;
    while(l1||l2)
    {
        int val1= l1?l1->val:0;//为空时做加法的位数为0
        int val2= l2?l2->val:0;
        
        int val3=val1+val2+carry;
        if(val3>=10)
        {
            val3=val3-10;
            carry=1;
        }
        else
        carry=0;
        q->next=new ListNode(val3);//创建新节点
        q=q->next;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;//当l1和l2为null时不取其next指针，一直让其保持空的状态
    }
    if(carry==1)//考虑最高位进位的情况
    q->next=new ListNode(1);
    return p->next;
}




