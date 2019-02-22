# 5.2.6 归并排序


```
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

```
