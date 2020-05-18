//
//  Demo2_7_design-linked-list.hpp
//  AlgorithmicPractice
//
//  Created by shuaibin on 2020/5/18.
//  Copyright © 2020 personal. All rights reserved.
//

#ifndef Demo2_7_design_linked_list_hpp
#define Demo2_7_design_linked_list_hpp

#include <stdio.h>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* head;

ListNode* MyLinkedList();
//获得链表中第index个节点的值
int get(int index);
//在链表头部插一个值为val的节点
void addAtHead(int val);
//在链表尾部添加一个值为val的节点
void addAtTail(int val);
//在索引为index的节点之前添加值为val的节点
void addAtIndex(int index,int val);
//删除索引为index的节点
void deleteAtIndex(int index);

#endif /* Demo2_7_design_linked_list_hpp */
