#  从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出
```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```
返回如下的二叉树：
```
            3
           / \
          9  20
            /  \
           15   7
```

解法:
```
//解法一:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int m = preorder.size();
    if(m == 0) return NULL;
    TreeNode* root = new TreeNode(preorder[0]);
    vector<int> preorder_left, inorder_left, preorder_right, inorder_right;
    //在inorder里面寻找根节点，划分左子树和右子树
    int i;
    //构造左子树的中序遍历
    for(i = 0; i < m; i ++){
        if(inorder[i] == preorder[0]) break;
        inorder_left.push_back(inorder[i]);
    }
    //构造右子树的中序遍历
    for(i = i + 1; i < m; i ++){
        inorder_right.push_back(inorder[i]);
    }
    for(int j = 1; j < m; j ++){
        //构造左子树的前序遍历
        if(j <= inorder_left.size())
            preorder_left.push_back(preorder[j]);
        //构造右子树的前序遍历
        else preorder_right.push_back(preorder[j]);
    }
    root->left = buildTree(preorder_left, inorder_left);
    root->right = buildTree(preorder_right, inorder_right);
    return root;
}


//解法二:
TreeNode* dfs(TreeNode* root,int root_pos,int inl,int inr,vector<int>& preorder, vector<int>& inorder)
{
    if(inl > inr)
        return root;
    if(root == nullptr)
    {
        root = new TreeNode(preorder[root_pos]);
    }
    int i = inl;
    while(preorder[root_pos] != inorder[i]) i++;    //寻找根节点在中序序列中的位置i
    
    root->left = dfs(root->left,root_pos+1,inl,i-1,preorder,inorder);        //递归地做由当前root划分成的二叉树的左子树
    root->right = dfs(root->right,root_pos+i-inl+1,i+1,inr,preorder,inorder);    //递归地做由当前root划分成的二叉树的右子树

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = nullptr;
    root = dfs(root,0,0,inorder.size()-1,preorder,inorder);
    return root;
}


//解法三:
class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

```

