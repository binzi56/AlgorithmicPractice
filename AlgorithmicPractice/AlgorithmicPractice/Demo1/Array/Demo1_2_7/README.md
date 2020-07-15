#  在排序数组中查找元素的第一个和最后一个位置


给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
```
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
```
示例 2:
```
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
```

解答:(无重复元素)
```
// 思路：最后一个值作为target，然后往左移动，最后比较start、end的值
int findMin(vector<int>& nums) {
    if(nums.size() == 0) return -1;

    int begin = 0, end = nums.size() - 1;
    while(begin + 1 < end){
        int mid = begin + (end - begin)/2;
        if(nums[mid] <= nums[end]){
             end = mid;
        }else{
             begin = mid;
        }
    }

    if(nums[begin] > nums[end]){
        return nums[end];
    }

    return nums[begin];
}
```
