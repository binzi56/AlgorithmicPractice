#  数组中的逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
```
输入: [7,5,6,4]
输出: 5
```

限制：
* 0 <= 数组长度 <= 50000

解法:
```
class Solution {
public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
        merge(nums, 0, nums.size() - 1);
        return res;
    }
    
    void merge(vector<int>& nums, int start, int end){
        if(nums.empty() || start >= end) return;

        int mid = (start + end) / 2;
        merge(nums, start, mid);
        merge(nums, mid + 1, end);

        hepler(nums, start, mid, end);
    }

    void hepler(vector<int>& nums, int start, int middle, int end){
        vector<int> temp(end - start + 1, 0);
        int i = start, j = middle + 1, k = 0;

        while(i <= middle && j<= end){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
                res += middle + 1 - i;
            }
        }

         while(i <= middle) temp[k++] = nums[i++];
         while(j <= end) temp[k++] = nums[j++];

         for(i = 0; i < k; i++){
             nums[start + i] = temp[i];
         }
    }
};
```
