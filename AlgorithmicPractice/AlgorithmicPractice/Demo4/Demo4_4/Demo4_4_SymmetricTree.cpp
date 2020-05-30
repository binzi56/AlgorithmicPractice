//
//  Demo4_4_SymmetricTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//  https://leetcode-cn.com/problems/symmetric-tree/solution/c-bfshe-dfsjie-jue-dui-cheng-er-cha-shu-wen-ti-by-/
//

#include "Demo4_4_SymmetricTree.hpp"

//DFS
bool dfs(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;
    return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return dfs(root->left, root->right);
}

//BFS
bool isSymmetric1(TreeNode* root) {
    if(!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qSize = q.size();
        vector<int> v(qSize);
        for(int i = 0; i < qSize; i++){
            TreeNode *t = q.front(); q.pop();
            v[i] = t ? t->val : INT_MIN;
            if(t){
                q.push(t->left);
                q.push(t->right);
            }
        }
        
        //判断是否回文
        for(int i = 0; i < qSize / 2; i++){
            if(v[i] != v[qSize - i - 1]) return false;
        }
    }
    return true;
}
