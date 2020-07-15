#  寻找旋转排序数组中的最小值

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：
```
输入：[3,4,5,1,2]
输出：1
```
示例 2：
```
输入：[2,2,2,0,1]
输出：0
```

解法:(包含重复元素)
```
int findMin(vector<int>& nums) {
    // 思路：跳过重复元素，mid值和end值比较，分为两种情况进行处理
    if(nums.size() == 0) return -1;

    int begin = 0, end = nums.size() - 1;
    while(begin + 1 < end){
        // 去除重复元素
        while(begin < end && nums[end] == nums[end - 1]) end--;
        while(begin < end && nums[begin] == nums[begin + 1]) begin++;

        int mid = begin + (end - begin) / 2;
        // 中间元素和最后一个元素比较（判断中间点落在左边上升区，还是右边上升区）
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

