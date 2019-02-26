//
//  Demo4_6_BinaryTreePreorderTraversal.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_6_BinaryTreePreorderTraversal.hpp"

//前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.push_back(p->val);
            p = p->left;
        } else {
            TreeNode *t = s.top();
            s.pop();
            p = t->right;
        }
    }
    return res;
}

//中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
    }
    return res;
}

//后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.insert(res.begin(), p->val);
            p = p->right;
        } else {
            TreeNode *t = s.top();
            s.pop();
            p = t->left;
        }
    }
    return res;
}
