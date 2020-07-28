# 5.2.5 快速排序

快速排序（Quicksort）是对冒泡排序的一种改进。
快速排序由C. A. R. Hoare在1962年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

```c++
//快速排序
void __quickSort(vector<int>& nums, int  low, int high){
    if (low >= high) return;
    
    int left = low;
    int right = high;
    int key = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= key) {
            right--;
        }
        
        nums[left] = nums[right];
        
        while (left < right && nums[left] <= key) {
             left++;
        }
        
        nums[right] = nums[left];
    }
    
    nums[left] = key;
    
    __quickSort(nums, low, left);
    __quickSort(nums, left + 1, high);
}


void quickSort(vector<int>& nums, int n){
    __quickSort(nums, 0, n - 1);
}
```
