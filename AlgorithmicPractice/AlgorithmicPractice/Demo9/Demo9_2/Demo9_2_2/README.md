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

```

