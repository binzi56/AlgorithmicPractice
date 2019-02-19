//
//  CommonTools.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/26.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "CommonTools.hpp"

template <typename T> void printfArr (vector<T>& arr){
    printf("============Array============\nArray[\n");
    for (int i = 0; i < arr.size(); i++) {
        if (typeid(arr[i]) == typeid(int)) {
            printf("%8d", arr[i]);
        }else if (typeid(arr[i]) == typeid(char)){
            printf("%8c", arr[i]);
        }else if (typeid(arr[i]) == typeid(string)){
            printf("%8s", arr[i]);
        }
        if (i < arr.size() - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("%6]\n============Array============");
}

void printfIntArr (vector<int>& arr){
//    printf("============Array============\nArray:[");
    printf("Array:[");
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) {
            printf("%d,", arr[i]);
        }else{
            printf("%d]\n", arr[i]);
        }
    }
//    printf("============Array============\n");
}


void printList(ListNode *head){
    ListNode *p = head->next;      //定义一个结点指针p指向头结点的下一个结点
    while(p){                    //如果p不为空则循环
        printf("%d->",p->val);
        p = p->next;               //移动指针p遍历链表
    }
}

//打印链表
void printLinkedList(ListNode *head) {
    ListNode *currentNode = head;
    printf("\n");
    while (currentNode != NULL) {
        printf("%d->",currentNode->val);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

//生成链表
ListNode* createLinkedList(int arr[], int n){
    if (n == 0){
        return NULL;
    }
    
    ListNode *head = new ListNode(arr[0]);
    ListNode *currentNode = head;
    
    for (int i = 1; i < n; ++i) {
        currentNode->next = new ListNode(arr[i]);
        currentNode = currentNode->next;
    }
    return head;
}


ListNode* createCycleList(int num) // 创建环形链表
{
    if (num <= 0)
        return NULL;
    ListNode* cur = NULL;
    ListNode* head = NULL;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 1;
    head = cur = node;
    for (int i = 1; i < num; i++)
    {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = i + 1;
        cur->next = node;
        cur = node;
    }
    cur->next = head;//让最后一个元素的指针域指向头结点，形成环
    return head;
}
