//
//  Demo4_2_InvertBinaryTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_2_InvertBinaryTree.hpp"


TreeNode* invertTree(TreeNode* root) {
    if ( root == NULL){
        return NULL;
    }
    
    TreeNode *tmpNode = root->left;
    root->left = root->right;
    root->right = tmpNode;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
