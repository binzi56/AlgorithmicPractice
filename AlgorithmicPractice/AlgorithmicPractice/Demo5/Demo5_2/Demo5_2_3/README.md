# 5.2.3 插入排序


```
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
```
