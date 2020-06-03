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

解法:
```
int findMin(vector<int>& nums) {
    int left = 0, mid, right = nums.size() - 1;

    while(left < right) {
        mid = left + (right - left) / 2;
        if(nums[mid] < nums[right]) right = mid;
        else left = mid + 1;
    }

    return nums[left];
}

// nums[mid] < nums[right]，即 [mid, right] 有序，[left, mid] 可能有序可能无序
// 此时最小值一定在 [left, mid] 区间（mid自己也可能是最小数）
// eg: [6, 7, 1, 2, 3, 4, 5] or [1, 2, 3, 4, 5, 6, 7]
if(nums[mid] < nums[right]) right = mid;

// nums[mid] > nums[right]，即 [left, mid] 有序，[mid, right] 一定无序，[mid + 1, right] 可能有序可能无序
// 此时最小值一定在 [mid + 1, right] 区间（mid自己就比右边界大了，一定不是最小值）
// eg: [4, 5, 6, 7, 1, 2, 3]
else left = mid + 1;


// 因为不存在重复元素，所以非空数组一定存在最小值
return nums[left];

```

