# 5.2.5 快速排序

快速排序（Quicksort）是对冒泡排序的一种改进。
快速排序由C. A. R. Hoare在1962年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

```
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
    int key = nums[first];
    
    while(first < last){
        while(first < last && nums[last] >= key){
            --last;
        }
        
        nums[first] = nums[last];
        
        while(first < last && nums[first] <= key){
            ++first;
        }
        
        nums[last] = nums[first];
    }
    nums[first] = key;
    __quickSort(nums, low, first-1);
    __quickSort(nums, first+1, high);
}
```
