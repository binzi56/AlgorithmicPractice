#  数据流的中位数

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

* void addNum(int num) - 从数据流中添加一个整数到数据结构中。
* double findMedian() - 返回目前所有元素的中位数。
示例：
```
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
```

进阶:

1. 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
2. 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？


解法:
```
//复杂度分析
时间复杂度：O(logn)。堆插入和删除需要 O(logn)，查找中位数需要 O(1)
空间复杂度：O(n)

class MedianFinder {
    priority_queue<int> lo;                              // 大顶堆
    priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // 加到大顶堆

        hi.push(lo.top());                               // 平衡
        lo.pop();

        if (lo.size() < hi.size()) {                     // 维护两个堆元素个数
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
         return large.size() == small.size() ? (large.top() + small.top()) / 2.0 : (double)large.top();
    }
};

```
