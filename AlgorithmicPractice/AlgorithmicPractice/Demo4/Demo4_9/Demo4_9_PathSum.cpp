//
//  Demo4_9_PathSum.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_9_PathSum.hpp"

bool hasPathSum(TreeNode *root, int sum) {
    if(root == NULL){
        return false;
    }
    
    if(root->left == NULL && root->right == NULL){
        return sum == root->val;
    }
    
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}
