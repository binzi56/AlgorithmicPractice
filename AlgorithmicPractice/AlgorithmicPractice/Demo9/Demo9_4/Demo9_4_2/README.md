#  多数元素

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:
```
输入: [3,2,3]
输出: 3
```
示例 2:
```
输入: [2,2,1,1,1,2,2]
输出: 2
```

解法:
```
//hash(48 ms, 19.1 MB)
class Solution 1{
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int n:nums)   
            if(++ mp[n] > nums.size()/2)   return n;         
        return -1;
    }
};

//Moore投票(36 ms, 18.9 MB)
class Solution 2{
public:
    int majorityElement(vector<int>& nums) {    //摩尔投票法，投我++，不投--，超过一半以上的人投我，那我稳赢
        int count=0,candidate;
        for(int n:nums)
        {
            if(count==0)        candidate=n;

            if(n==candidate)    count++;
            else                count--;
        }
        return candidate;
    }
};

```


[c++ 5种方法 排序，哈希，投票，随机数，位运算-z](https://leetcode-cn.com/problems/majority-element/solution/3xing-c-ha-xi-z-by-zrita/)
