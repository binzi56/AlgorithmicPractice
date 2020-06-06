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

解法:
```
//解法一:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index  = search(nums, 0 ,nums.size()-1, target);
        if(index == -1) return {-1, -1};
        // 开始左查找
        int left_end = index - 1;
        while(left_end >= 0 && nums[left_end] == target){
            left_end = search(nums, 0, left_end, target) - 1;
        }
        // 开始右查找
        int right_start = index + 1;
        while(right_start < nums.size()  && nums[right_start] == target){
            right_start = search(nums, right_start, nums.size()-1, target) + 1;
        }

        // 返回结果
        return {left_end + 1, right_start - 1};
    }
private:
    int search(vector<int>& nums, int start, int end, int target){
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};

//解法二:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
          if(nums.size() < 1) return res;
          // 第一次二分查找，找到左边界
          int left = 0, right = nums.size();
          while(left < right){
              int mid = (left + right) / 2;
              nums[mid] < target ? left = mid + 1 : right = mid;
          }

          if(left == nums.size()) return res;
          if(target == nums[left]) res[0] = left;
          else return res;
          // 第二次二分查找，找到右边界
          right = nums.size();
          while(left < right){
              int mid = (left + right) / 2;
              nums[mid] > target ? right = mid : left = mid + 1; 
          }
          res[1] = left - 1;
          return res;
    }
};

```
