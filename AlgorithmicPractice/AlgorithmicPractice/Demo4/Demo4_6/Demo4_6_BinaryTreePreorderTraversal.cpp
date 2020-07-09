//
//  Demo4_6_BinaryTreePreorderTraversal.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_6_BinaryTreePreorderTraversal.hpp"

/*
   方法一:
    栈
 */
//前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;  //保存结果
    stack<TreeNode*> call;  //调用栈
    if(root!=nullptr) call.push(root);  //首先介入root节点
    while(!call.empty()){
        TreeNode *t = call.top();
        call.pop();  //访问过的节点弹出
        if(t!=nullptr){
            if(t->right) call.push(t->right);  //右节点先压栈，最后处理
            if(t->left) call.push(t->left);
            call.push(t);  //当前节点重新压栈（留着以后处理），因为先序遍历所以最后压栈
            call.push(nullptr);  //在当前节点之前加入一个空节点表示已经访问过了
        }else{  //空节点表示之前已经访问过了，现在需要处理除了递归之外的内容
            res.push_back(call.top()->val);  //call.top()是nullptr之前压栈的一个节点，也就是上面call.push(t)中的那个t
            call.pop();  //处理完了，第二次弹出节点（彻底从栈中移除）
        }
    }
    return res;
}

//中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> call;
    if(root!=nullptr) call.push(root);
    while(!call.empty()){
        TreeNode *t = call.top();
        call.pop();
        if(t!=nullptr){
            if(t->right) call.push(t->right);
            call.push(t);  //在左节点之前重新插入该节点，以便在左节点之后处理（访问值）
            call.push(nullptr); //nullptr跟随t插入，标识已经访问过，还没有被处理
            if(t->left) call.push(t->left);
        }else{
            res.push_back(call.top()->val);
            call.pop();
        }
    }
    return res;
}

//后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> call;
    if(root!=nullptr) call.push(root);
    while(!call.empty()){
        TreeNode *t = call.top();
        call.pop();
        if(t!=nullptr){
            call.push(t);  //在右节点之前重新插入该节点，以便在最后处理（访问值）
            call.push(nullptr); //nullptr跟随t插入，标识已经访问过，还没有被处理
            if(t->right) call.push(t->right);
            if(t->left) call.push(t->left);
        }else{
            res.push_back(call.top()->val);
            call.pop();
        }
    }
    return res;
}


/*
     方法二:
     递归
 */
vector<int> result;

//前序遍历
void preorderHelper(TreeNode *node){
    if(node == nullptr) return;
    result.push_back(node->val);
    preorderHelper(node->left);
    preorderHelper(node->right);
}

vector<int> preorderTraversal1(TreeNode* root) {
    preorderHelper(root);
    return result;
}

//中序遍历
void inorderHelper(TreeNode *node){
    if(node == nullptr) return;
    inorderHelper(node->left);
    result.push_back(node->val);
    inorderHelper(node->right);
}

vector<int> inorderTraversal1(TreeNode* root) {
    inorderHelper(root);
    return result;
}

//后序遍历
void postorderHelper(TreeNode *node){
    if(node == nullptr) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    result.push_back(node->val);
}

vector<int> postorderTraversal1(TreeNode* root) {
    postorderHelper(root);
    return result;
}


/*
    方法三:
    栈
*/
//前序遍历
vector<int> preorderTraversal2(TreeNode* root) {
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
vector<int> inorderTraversal2(TreeNode* root) {
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
vector<int> postorderTraversal2(TreeNode* root) {
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





