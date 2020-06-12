#  最小的k个数

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：
```
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```
示例 2：
```
输入：arr = [0,1,2,1], k = 1
输出：[0]
```

限制：
```
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
```

解法:
```
//快排(找到前k个就返回,速度比用sort要快,因为没有全部排序)
class Solution {
public:
    vector<int> res;
    void quick_sort(vector<int> &q,int k,int l,int r)
    {
        if(l>=r)  return;
        
        int i=l-1,j=r+1,mid=q[l+r >>1];

        while(i<j)
        {
            do i++;while(q[i]<mid);
            do j--;while(q[j]>mid);
            if(i<j)   swap(q[i],q[j]) ;
        }

        if(j-l+1 ==k ) return;
        else if(j-l+1 >k) quick_sort(q,k,l,j);
        else  quick_sort(q,k-(j-l+1),j+1,r);


    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         quick_sort(arr,k,0,arr.size()-1);
        for(int i=0;i<k;i++)  res.push_back(arr[i]);
        return res;
    }
};

//调用函数
class Solution 2{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort (arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
```
