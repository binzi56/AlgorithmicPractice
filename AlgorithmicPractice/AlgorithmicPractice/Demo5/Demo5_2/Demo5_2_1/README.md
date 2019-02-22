# 5.2.1 冒泡排序


```
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
```
