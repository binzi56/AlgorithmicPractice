//
//  Demo4_5_SameTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_5_SameTree.hpp"

bool isSameTree(TreeNode* p,TreeNode* q){
    if(p == NULL && q != NULL){
        return false;
    }
    else if(p !=NULL && q ==NULL){
        return false;
    }
    else if(p == NULL && q == NULL){
        return true;
    }
    else if((p != NULL && q != NULL)&& (p->val !=q->val)){
        return false;
    }
    else{
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
}
