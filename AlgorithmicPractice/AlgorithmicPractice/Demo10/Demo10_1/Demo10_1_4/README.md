#  数组中数字出现的次数 II

在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 

示例 1：
```
输入：nums = [3,4,3,3]
输出：4
```
示例 2：
```
输入：nums = [9,1,7,9,7,9,7]
输出：1
```

限制：

* 1 <= nums.length <= 10000
* 1 <= nums[i] < 2^31


解法:
```
//hash
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto n:nums) mp[n]++;
        for(auto n:nums){
            if(mp[n]==1){
                return n;
            }
        }
        return -1;
    }
};

//状态机(a表示每一位余数是否为1，b表示每一位余数是否为2，二者不同时为真，根据num更新a和b。)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            a = a ^ num & ~b;
            b = b ^ num & ~a;
        }
        return a;
    }
};

//位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i 的值大于0即为真
                if(n & (1 << i)) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if(cnt % 3 == 1) ans ^= (1 << i);
        }
        return ans;
    }
};
```

