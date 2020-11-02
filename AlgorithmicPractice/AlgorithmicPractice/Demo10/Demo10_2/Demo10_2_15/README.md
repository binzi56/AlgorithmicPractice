#  柱状图中最大的矩形

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

示例:
```
输入: [2,1,5,6,2,3]
输出: 10
```

解法:
```c++
class Solution {
public:
    //保证是单调递增栈, 这样就可以访问后面的矩形
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;

        stack<int> s;
        int maxArea = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[i] < heights[s.top()]){
                int top = s.top();
                s.pop();
                maxArea = max(maxArea, heights[top] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }

        return maxArea;
    }
};
```