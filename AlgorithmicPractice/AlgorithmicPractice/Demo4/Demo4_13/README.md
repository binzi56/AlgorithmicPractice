#  二叉搜索树的第k大节点

给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:
```
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
```
示例 2:
```
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
```

限制：

* 1 ≤ k ≤ 二叉搜索树元素个数

解法:
```
//大顶堆(32 ms    24.5 MB)
class Solution 1{
public:
    priority_queue<int> pq; 
    void dfs(TreeNode* root){
        pq.push(root->val);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};

//中序遍历(二叉搜索树的一个特征就是中序遍历递增)       (36 ms    24.3 MB)
class Solution 2{
    vector<int> ans;
    void traverse(TreeNode* root){
        if(root == NULL) return;
        traverse(root->left);
        ans.push_back(root->val);
        traverse(root->right);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        traverse(root);
        return ans[ans.size() - k];
    }
};

```

