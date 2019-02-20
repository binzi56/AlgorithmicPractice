//
//  Demo4_3_BalancedBinaryTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_3_BalancedBinaryTree.hpp"


int height(TreeNode* root) {
    
    if(root==NULL){
        return 0;
    }else{
        int l=height(root->left);
        int r=height(root->right);
        return 1+((l>r)?l:r);
    }
}

bool isBalanced(TreeNode *root) {
    
    if(root==NULL){
        
        return true;
        
    }else{
        
        int l,r;
        
        l=height(root->left);
        r=height(root->right);
        
        if((l > r+1)||(r > l+1)){
            return false;
        }else{
            return isBalanced(root->left)&&isBalanced(root->right);
        }
    }
}
