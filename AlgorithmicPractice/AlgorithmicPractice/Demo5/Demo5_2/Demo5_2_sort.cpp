//
//  Demo5_2_sort.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/21.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo5_2_sort.hpp"


void sortDemoTest(){
    
}

//冒泡排序
void bubbleSort(vector<int>& nums, int n){
    for (int i = 0; i < n; i++){
        for (int j = n - 1; j > i; j--){
            if (nums[j] < nums[j - 1]){
                __swap(nums[j], nums[j-1]);
            }
        }
    }
}

//选择排序
void selectSort(vector<int>& nums, int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n ; ++j) {
            if (nums[j] < nums[min]){
                min = j;
            }
        }
        
        if (min != i){
            __swap(nums[i],nums[min]);
        }
    }
}

//插入排序
void insertSort(vector<int>& nums, int n){
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0  ; j--) {
            if (nums[j] < nums[j - 1]){
                __swap(nums[j],nums[j -1]);
            } else{
                break;
            }
        }
    }
}

//希尔排序
void shellSort(vector<int>& nums, int n){
    int temp;
    int gap = n;
    do{
        gap = gap / 3 + 1;
        for (int i = gap; i < n; i++)
        {
            if (nums[i] < nums[i - gap]){
                temp = nums[i];
                int j;
                for (j = i; j >= gap && temp < nums[j - gap]; j -= gap){
                    nums[j] = nums[j - gap];
                }
                nums[j] = temp;
            }
        }
    } while (gap > 1);
}


//快速排序
void quickSort(vector<int>& nums, int n){
    __quickSort(nums,0,n - 1);
    
}
void __quickSort(vector<int>& nums, int left,int right){
    if (left > right){
        return;
    }
    
    int mid = (left + right) / 2;
    
    if (nums[left] > nums[right])
        __swap(nums[left], nums[right]);
    if (nums[mid] > nums[right])
        __swap(nums[mid], nums[right]);
    if (nums[mid] > nums[left])
        __swap(nums[left], nums[mid]);
    
    int temp = nums[left];
    int i = left;
    int j = right;
    
    while (i != j){
        while (nums[j] >= temp && i<j)
            j--;
        while (nums[i] <= temp&& i<j)
            i++;
        
        if (i != j){
            __swap(nums[i], nums[j]);
        }
    }

    nums[left] = nums[j];
    nums[j] = temp;
    
    __quickSort(nums,left, j - 1);
    __quickSort(nums, j + 1, right);
}


//归并排序
void mergeSort(vector<int>& nums,int n){
    __cutSortArray(nums, 0, n - 1);
}
void __cutSortArray(vector<int>& nums,int low,int high){
    int mid = (low + high) / 2;
    if (low < high){
        __cutSortArray(nums, low, mid);
        __cutSortArray(nums, mid + 1, high);
        __mergeCutSort(nums, low, mid, high);
    }
}
void __mergeCutSort(vector<int>& nums, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int *temp = new int[high - low + 1];
    int count = 0;
    
    while (i <= mid && j <= high){
        if (nums[i] <= nums[j]){
            temp[count++] = nums[i++];
        }else{
            temp[count++] = nums[j++];
        }
    }
    
    while (i <= mid){
        temp[count++] = nums[i++];
    }
    
    while (j <= high){
        temp[count++] = nums[j++];
    }
    
    for (int i = low,k=0; i <= high; i++,k++){
        nums[i] = temp[k];
    }
}





void __swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
