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

void sortDemoTest();

void __swap(int &a, int &b);
void __quickSort(vector<int>& nums, int low, int high);
void __cutSortArray(vector<int>& nums,int low,int high);
void __mergeCutSort(vector<int>& nums, int low, int mid, int high);

#endif /* Demo5_2_sort_hpp */
