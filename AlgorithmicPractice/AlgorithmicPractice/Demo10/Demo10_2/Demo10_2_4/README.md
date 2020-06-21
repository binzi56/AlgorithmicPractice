#  丑数 II

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:
```
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```
说明:  

* 1 是丑数。
* n 不超过1690。

解法:
```
//动态规划d
class Solution 1{
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i ++){
            dp[i] = min(min(dp[p2]*2, dp[p3]*3), dp[p5]*5);
            if(dp[i] == dp[p2]*2) p2++;
            if(dp[i] == dp[p3]*3) p3++;
            if(dp[i] == dp[p5]*5) p5++;
        }
        return dp[n - 1];
    }
};

//优先队列(小顶堆)
class Solution 2{
public:
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q;
        double answer=1;
        for (int i=1;i<n;++i)
        {
            q.push(answer*2);
            q.push(answer*3);
            q.push(answer*5);
            answer=q.top();
            q.pop();
            while (!q.empty() && answer==q.top())
                q.pop();
        }
        return answer;
    }
};
```


