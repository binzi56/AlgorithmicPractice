#  构建乘积数组

给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

示例:
```
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
```

提示：

* 所有元素乘积之和不会溢出 32 位整数
* a.length <= 100000

解法:
```
解题思路:
通过 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]B[i]=A[0]×A[1]×…×A[i−1]×A[i+1]×…×A[n−1] ，我们发现 B[i]B[i] 就是 A[i]A[i] 左边所有元素的积 乘 A[i]A[i] 右边所有元素的积。
利用对称关系，经过两遍对称运算就能得到最终的结果。

对称遍历
* 从左往右遍历累乘，结果保存在数组 ret 中，此时 ret[i] 表示，A[i]左边所有元素的乘积
* 然后从右往左遍历累乘，获取A[i] 右边所有元素的乘积
* 两边遍历之后得到的 ret，就是最终结果

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ret(n, 1);
        int left = 1;
        for (int i = 0; i < n; i ++) {
            ret[i] = left;
            left *= a[i];
        } 
        int right = 1;
        for (int i = n-1; i >= 0; i --) {
            ret[i] *= right;
            right *= a[i];
        }
        return ret;
    }
};

```
