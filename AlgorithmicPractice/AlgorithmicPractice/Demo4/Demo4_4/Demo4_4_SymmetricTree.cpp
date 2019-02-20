//
//  Demo4_4_SymmetricTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_4_SymmetricTree.hpp"


bool isSymmetric(TreeNode* root) {
    if (root == NULL){
        return true;
    }
    
    return checkLeftAndRightNodes(root->left,root->right);
}

bool checkLeftAndRightNodes(TreeNode *leftNode, TreeNode *rightNode){
    if (leftNode == NULL && rightNode == NULL){
        return true;
    }
    
    if (leftNode == NULL || rightNode == NULL){
        return false;
    }
    
    if (leftNode->val !=  rightNode -> val){
        return false;
    }else {
        return checkLeftAndRightNodes(leftNode -> left, rightNode->right)
        &&  checkLeftAndRightNodes(leftNode -> right, rightNode->left);
    }
}
