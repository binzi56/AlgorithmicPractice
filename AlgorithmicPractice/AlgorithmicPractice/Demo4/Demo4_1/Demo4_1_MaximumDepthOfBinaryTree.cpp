//
//  Demo4_1_MaximumDepthOfBinaryTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_1_MaximumDepthOfBinaryTree.hpp"

//DFS
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//BFS
int maxDepth1(TreeNode* root) {
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()){
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans++;
    }
    return ans;
}

