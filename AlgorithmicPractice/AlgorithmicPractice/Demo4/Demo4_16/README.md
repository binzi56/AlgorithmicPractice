#  二叉树的完全性检验

给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

 

示例 1：

输入：[1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。

解法：
```c
层序遍历

两个条件 排除非完全二叉树：
1、如果一个节点有右孩子，但没有左孩子，则不是完全二叉树 return false
2、如果一个节点仅有左孩子，或左右都没有（即没有右孩子），则后续的节点都必须是叶子节点，才能是完全二叉树， 只要出现非叶子节点 return false


bool isCompleteTree(TreeNode* root) {
    
    queue<TreeNode *> q;
    q.push(root);

    bool leaf = false; //是否必须为叶子节点
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        
        if(!node->left && node->right) return false; //仅有右子节点，无左子节点

        if(leaf){
            //前面出现过无右子节点的 (只有左 或 左右都没有的) 后续所有节点必须为叶子节点
            if(node->left || node->right) return false;
        }

        if(node->left) q.push(node->left);

        if(node->right){
            q.push(node->right);
        }else{
            //右为空 则后续节点必须为叶子节点
            leaf = true;
        }
    }

    return true;
}
```

