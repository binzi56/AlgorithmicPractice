#  数组中重复的数字

找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：
```
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```

限制：

* 2 <= n <= 100000

解答:
```
//hash(132 ms, 28.2 MB)
class Solution 1{
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(++m[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};

//排序法(84 ms, 23 MB)
class Solution 2{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        if(nums.empty())
            return -1;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                else
                    swap(nums[i], nums[nums[i]]);
            }
        }
        
        return -1;
    }
}

```
