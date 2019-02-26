//
//  Demo5_2_sort.hpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/21.
//  Copyright © 2019 personal. All rights reserved.
//  C++的排序方式
//  https://blog.csdn.net/chen1234520nnn/article/details/82084700

#ifndef Demo5_2_sort_hpp
#define Demo5_2_sort_hpp

#include <stdio.h>
#include "Demo1_2_1_deleteArrRepeat.hpp"
#include "CommonTools.hpp"

void sortDemoTest();

void __swap(int &a, int &b);
void __quickSort(vector<int>& nums, int low, int high);
void __merge(vector<int>& nums, int start, int mid, int end);
void __mergeGroups(vector<int>& nums, int len, int gap);

//插入排序
void insertSort(vector<int>& nums, int n);
//快速排序
void quickSort(vector<int>& nums, int n);

//归并排序(从上往下)
void mergeSortUpToDown(vector<int>& nums, int start, int end);
//归并排序(从下往上)
void mergeSortDownToUp(vector<int>& nums, int n);

#endif /* Demo5_2_sort_hpp */
