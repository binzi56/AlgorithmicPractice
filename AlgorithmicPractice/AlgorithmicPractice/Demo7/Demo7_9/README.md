#  n个骰子的点数

把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:
```
输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
```
示例 2:
```
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
```

限制：

* 1 <= n <= 11


解法:
```
class Solution 1{
public:
    vector<double> twoSum(int n) {
        //n <= 11
        vector<vector<double>>dp(n + 1, vector<double>(6*n + 1, 0));
        vector<double> ans;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= 6*i; j++){   //所有点数之和
                if(i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int k = 1; k <= 6; k++){
                    if(j - k >= i - 1) dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for(int i = n; i <= 6*n; i++){
            //投完n个骰子后，点数 i 出现的次数 ÷ 所有点数出现的次数之和。也就是点数 i 出现的概率
            ans.push_back(dp[n][i] * pow(1.0/6, n));  
        }
        return ans;
    }
};


class Solution 2{
public:
    vector<double> twoSum(int n) {
        const double D16 = 1.0 / 6.0;
        vector<double> res(6*n+1, 0.0);
        for (int i = 1; i <= 6; i++) {
            res[i] = D16;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 6*i; j >= i; j--) {
                res[j] = 0;
                for (int k = j-1; k >= i-1 && k >= j-6; k--) {
                    res[j] += (res[k] * D16);
                }
            }
        }
        return vector<double>(res.begin()+n, res.end());
    }
};
```
