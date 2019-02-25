# 5.2.6 归并排序

归并排序（`MERGE-SORT`）是建立在归并操作上的一种有效的排序算法,该算法是采用分治法（`Divide and Conquer`）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。

```
//归并排序(从上往下)
void mergeSortUpToDown(vector<int>& nums, int start, int end){
    if(nums.empty() || start >= end){
        return;
    }
    
    int mid = (end + start)/2;
    mergeSortUpToDown(nums, start, mid);
    mergeSortUpToDown(nums, mid+1, end);
    
    __merge(nums, start, mid, end);
}

void __merge(vector<int>& nums, int start, int mid, int end){
    int *temp = new int[end-start+1];    
    int i = start;                       
    int j = mid + 1;                     
    int k = 0;                           
    
    while(i <= mid && j <= end){
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    
    while(i <= mid)
        temp[k++] = nums[i++];
    
    while(j <= end)
        temp[k++] = nums[j++];
    
    for (i = 0; i < k; i++)
        nums[start + i] = temp[i];
    
    delete[] temp;
}
```
