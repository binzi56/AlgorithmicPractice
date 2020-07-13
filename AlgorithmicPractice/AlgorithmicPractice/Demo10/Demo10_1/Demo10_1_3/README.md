#  数组中数字出现的次数

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
```
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
```
示例 2：
```
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
```

限制：

* 2 <= nums.length <= 10000

解法:
```
解题思路：全员进行异或操作即可。考虑异或操作的性质：对于两个操作数的每一位，相同结果为 00，不同结果为 11。那么在计算过程中，成对出现的数字的所有位会两两抵消为 00，最终得到的结果就是那个出现了一次的数字。

//位运算
解法一
vector<int> singleNumbers(vector<int>& nums) {
    int s = 0;
    for (int num : nums) {
        s ^= num;  //先对所有数字进行一次异或，得到两个出现一次的数字的异或值
    }
    int k = s & (-s);  //寻找两个不同数字异或值的最低为1的位
    vector<int> res(2,0);
    for(int num : nums){
        if(num & k){
            res[0] ^= num;
        }else{
            res[1] ^= num;
        }
    }
    return res;
}

解法二:
vector<int> singleNumber(vector<int>& nums) {
    int s = 0;
    
    for(auto n : nums){
        s = s ^ n;  //先对所有数字进行一次异或，得到两个出现一次的数字的异或值
    }
    
    s = (s & (s - 1)) ^ s;   // 去掉末尾的1后异或s就得到最后一个1的位置 
    vector<int> res(2,0);
    for(auto n : nums){
        if(n & s){
           res[0] ^= n;
        }else{
           res[1] ^= n;
        }
    }

    return res;
}
```
