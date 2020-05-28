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

TreeNode* invertTree1(TreeNode* root) {
  if(!root) return nullptr;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
      TreeNode* node =  q.front();
      q.pop();
      if(node){
          swap(node->left, node->right);
          q.push(node->left);
          q.push(node->right);
      }
  }
  return root;
}

