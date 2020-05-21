#  滑动窗口

## 滑动窗口最大值

解答:
```
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }
    
    int max() { return data.front(); }
    
    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //先填满窗口的前 k - 1
            window.push(nums[i]);
        } else { // 窗口向前滑动
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]); // nums[i - k + 1] 就是窗口最后的元素
        }
    }
    return res;
}


vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> deq;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        //新元素入队时如果比队尾元素大的话就替代队尾元素
        while(!deq.empty() && nums[i] > nums[deq.back()]){
            deq.pop_back();
        }
        //检查队首的index是否在窗口内，不在的话需要出队
        if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
        deq.push_back(i);
        if (i >= k -1) ans.push_back(nums[deq.front()]);
    }
    return ans;
}

```

## 队列的最大值

解答:
```
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};
```
