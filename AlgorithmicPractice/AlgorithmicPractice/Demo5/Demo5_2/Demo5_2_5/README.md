# 5.2.5 快速排序

快速排序（Quicksort）是对冒泡排序的一种改进。
快速排序由C. A. R. Hoare在1962年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

```
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

```
