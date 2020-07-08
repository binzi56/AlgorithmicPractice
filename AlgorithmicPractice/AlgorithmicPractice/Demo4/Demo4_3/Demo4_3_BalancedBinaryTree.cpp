//
//  Demo4_3_BalancedBinaryTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_3_BalancedBinaryTree.hpp"

/*
 自底向上
     遍历到最底部，开始从零计算从叶节点开始向上的高度
     每个节点都对比左右子树的高度
 */
int box(TreeNode* root){
    if(!root)   return 0;
    
    int l = box(root -> left);
    int r = box(root -> right);

    if(l == -1 || r == -1) return -1;

    return abs(l - r) < 2 ? max(l, r) + 1 : - 1;
}
bool isBalanced(TreeNode* root) {
    return box(root) != -1;
}

/*
 自顶向下
     每个节点都计算且对比左右子树的高度
     此方法会重复计算
 */
int depth(TreeNode* root){
    if(!root)   return 0;
    return max(depth(root -> left), depth(root -> right)) + 1;
}
bool isBalanced1(TreeNode* root) {
    if(!root)   return true;
    return abs(depth(root -> left) - depth(root -> right)) < 2 && isBalanced(root -> left) && isBalanced(root -> right);
}

