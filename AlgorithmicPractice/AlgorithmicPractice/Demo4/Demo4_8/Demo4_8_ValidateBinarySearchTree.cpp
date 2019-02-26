//
//  Demo4_8_ValidateBinarySearchTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_8_ValidateBinarySearchTree.hpp"


bool isValidBST(TreeNode* root) {
    TreeNode* pre = NULL;
    return __isValidBST(root, pre);
}
bool __isValidBST(TreeNode* root, TreeNode*& pre){
    if(root == NULL) return true;
    if(!__isValidBST(root->left, pre)) return false;
    if(pre != NULL && pre->val >= root->val) return false;
    pre = root;
    return __isValidBST(root->right, pre);
}
