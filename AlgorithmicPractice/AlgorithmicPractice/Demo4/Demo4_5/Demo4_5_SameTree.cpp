//
//  Demo4_5_SameTree.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//
// https://leetcode-cn.com/problems/same-tree/solution/di-gui-he-die-dai-c-by-irelia-7/

#include "Demo4_5_SameTree.hpp"

//DFS
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

bool isSameTree1(TreeNode* p, TreeNode* q) {
    stack<TreeNode*> S;
    S.push(q);
    S.push(p);
    TreeNode* p_temp;
    TreeNode* q_temp;
    while(!S.empty()){
        p_temp=S.top();
        S.pop();
        q_temp=S.top();
        S.pop();
        if(p_temp==NULL&&q_temp==NULL)continue;
        else if(p_temp!=NULL || q_temp!=NULL)return false;
        else if(p_temp->val!=q_temp->val)return false;
        else{
            S.push(q_temp->right);
            S.push(p_temp->right);
            S.push(q_temp->left);
            S.push(p_temp->left);
        }
    }
    return true;
}
