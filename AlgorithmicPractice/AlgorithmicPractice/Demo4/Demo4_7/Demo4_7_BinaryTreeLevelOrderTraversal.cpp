//
//  Demo4_7_BinaryTreeLevelOrderTraversal.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_7_BinaryTreeLevelOrderTraversal.hpp"

//BFS(广度优先搜索->队列)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector <vector <int>> ret;
    if (!root) return ret;

    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(vector <int> ());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return ret;
}

//DFS(深度优先搜索->递归)
vector<vector<int>> res;
void addVector(TreeNode* root,int level)
{
  if(root == NULL)    return;
  if(res.size() == level)       res.resize(level+1);    //level表示层数，也对应二维数组的第一层索引，
  res[level].push_back(root->val);
  addVector(root->left,level+1);
  addVector(root->right,level+1);
}

vector<vector<int>> levelOrder1(TreeNode* root)
{
  addVector(root,0);      //调用递归函数
  return res;
}


//BFS(方法二)
vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;  // 树为空则直接返回
    vector<int> each_level;  //依次存储每一层从左往右的结点值
    queue<TreeNode*>q;  // 队列，先进进出(FIFO)
    q.push(root);
    while(!q.empty()) {
        int size = q.size();  // 每层的结点数
        for(int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();  // 将现结点加入each_level
            each_level.push_back(curr->val);
            // 非空结点不计入答案，所以要判断现结点的左右结点是否为空
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            q.pop();  //记得弹出之前的头结点
        }
        ans.push_back(each_level);  // 把每层的结点存入ans
        each_level.clear();  //  清除每层的结点，以便添加下一层的非空结点
    }
    return ans;

}

