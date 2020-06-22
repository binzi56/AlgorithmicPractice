#  扑克牌中的顺子

从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
```
输入: [1,2,3,4,5]
输出: True
```

示例 2:
```
输入: [0,0,1,2,5]
输出: True
```

限制：

* 数组长度为 5 
* 数组的数取值为 [0, 13] .

解法:
```
//map
class Solution 1{
public:
    bool isStraight(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int upper = -1;
        int lower = 100;

        for (auto num: nums) {
            cnt[num]++;
            if (num != 0) {
                if (cnt[num] > 1) return false;
                upper = max(upper, num);
                lower = min(lower, num);
            }
        }

        if (cnt[0] >= 4) return true;
        int delta = upper - lower;
        if (delta >= 5) return false;

        return true;        
    }
};

//排序
class Solution 2{
public:
    bool isStraight(vector<int>& nums) {
        int num1 = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i ++){
            if(nums[i] == 0) num1 ++;
            else if(nums[i] == nums[i + 1]) return false;
            else num1 -= (nums[i + 1] - nums[i] - 1);
        }
        return num1 >= 0;
    }
};
```
