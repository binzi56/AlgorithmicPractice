//
//  Demo4_1_MaximumDepthOfBinaryTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_1_MaximumDepthOfBinaryTree.hpp"


int maxDepth(TreeNode* root) {
    if (root == NULL){
        return 0;
    }
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    
    return l > r ? l + 1:r + 1;
}
