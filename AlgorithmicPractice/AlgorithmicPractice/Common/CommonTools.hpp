//
//  CommonTools.hpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/26.
//  Copyright © 2018年 personal. All rights reserved.
//

#ifndef CommonTools_hpp
#define CommonTools_hpp

#define CLASSFOO_VECTOR(type, name, ...) \
static const type name##_a[] = __VA_ARGS__; \
std::vector<type> name(name##_a, name##_a + sizeof(name##_a) / sizeof(*name##_a))

//CLASSFOO_VECTOR(int,foo,{1,2,3,4,5,6,7});

#include <stdio.h>
#include <vector>
#include <string>
#include "Demo2_1_singleLinkedListFlip.hpp"
using namespace std;

template <typename T> void printfArr (vector<T>& arr);

void printfIntArr (vector<int>& arr);

void printLinkedList(ListNode *head);

int calculateLength(ListNode *head);

//生成链表
ListNode* createLinkedList(int arr[], int n);



#endif /* CommonTools_hpp */
