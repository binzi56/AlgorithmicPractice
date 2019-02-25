//
//  Demo5_2_sort.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/21.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo5_2_sort.hpp"


void sortDemoTest(){
    int a[] = {80,30,60,40,20,10,50,70};
    int len = (sizeof(a)) / (sizeof(a[0]));
//    mergeSortUpToDown(a, 0, len-1);        // 归并排序(从上往下)
//    mergeSortDownToUp(a, len);            // 归并排序(从下往上)
}

//冒泡排序
void bubbleSort(vector<int>& nums, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (nums[j] > nums[j + 1]){
                __swap(nums[j], nums[j+1]);
            }
        }
    }
}

//选择排序
void selectSort(vector<int>& nums, int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n ; j++) {
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
        for (int j = i; j > 0; j--) {
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
void __quickSort(vector<int>& nums, int low,int high){
    if(low >= high){
        return;
    }
    int first = low;
    int last = high;
    int key = nums[first];//用字表的第一个记录作为枢轴
    
    while(first < last){
        while(first < last && nums[last] >= key){
            --last;
        }
        
        nums[first] = nums[last];//将比第一个小的移到低端
        
        while(first < last && nums[first] <= key){
            ++first;
        }
        
        nums[last] = nums[first];//将比第一个大的移到高端
    }
    nums[first] = key;//枢轴记录到位
    __quickSort(nums, low, first-1);
    __quickSort(nums, first+1, high);
}

//归并排序
/*
 * 将一个数组中的两个相邻有序区间合并成一个
 *
 * 参数说明：
 *     nums -- 包含两个有序区间的数组
 *     start -- 第1个有序区间的起始地址。
 *     mid   -- 第1个有序区间的结束地址,也是第2个有序区间的起始地址。
 *     end   -- 第2个有序区间的结束地址。
 */
void __merge(vector<int>& nums, int start, int mid, int end){
    int *tmp = new int[end-start+1];    // tmp是汇总2个有序区的临时区域
    int i = start;                      // 第1个有序区的索引
    int j = mid + 1;                    // 第2个有序区的索引
    int k = 0;                          // 临时区域的索引
    
    while(i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    
    while(i <= mid)
        tmp[k++] = nums[i++];
    
    while(j <= end)
        tmp[k++] = nums[j++];
    
    // 将排序后的元素，全部都整合到数组a中
    for (i = 0; i < k; i++)
        nums[start + i] = tmp[i];
    
    delete[] tmp;
}

//归并排序(从上往下)
void mergeSortUpToDown(vector<int>& nums, int start, int end){
    if(nums.empty() || start >= end){
        return;
    }
    
    int mid = (end + start)/2;
    mergeSortUpToDown(nums, start, mid);  //递归排序nums[start...mid]
    mergeSortUpToDown(nums, mid+1, end);  //递归排序nums[mid+1...end]
    
    //nums[start...mid] 和 nums[mid...end]是两个有序空间，
    //将它们排序成一个有序空间nums[start...end]
    __merge(nums, start, mid, end);
}


/*
 * 对数组a做若干次合并：数组a的总长度为len，将它分为若干个长度为gap的子数组；
 *             将"每2个相邻的子数组" 进行合并排序
 *
 * 参数说明：
 *     nums -- 待排序的数组
 *     len -- 数组的长度
 *     gap -- 子数组的长度
 */
void __mergeGroups(vector<int>& nums, int len, int gap){
    int i;
    // 将"每2个相邻的子数组" 进行合并排序
    for(i = 0; i+2*gap-1 < len; i+=(2*gap))
    {
        __merge(nums, i, i+gap-1, i+2*gap-1);
    }
    
    // 若 i+gap-1 < len-1，则剩余一个子数组没有配对
    // 将该子数组合并到已排序的数组中
    if ( i+gap-1 < len-1)
    {
        __merge(nums, i, i + gap - 1, len - 1);
    }
}

//归并排序(从下往上)
void mergeSortDownToUp(vector<int>& nums, int n)
{
    int first = 0;
    
    if (nums.empty() || n<=0){
        return;
    }
    
    for(n = 1; first < n; n*=2){
        __mergeGroups(nums, n, first);
    }
}

//交互数组元素
void __swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
