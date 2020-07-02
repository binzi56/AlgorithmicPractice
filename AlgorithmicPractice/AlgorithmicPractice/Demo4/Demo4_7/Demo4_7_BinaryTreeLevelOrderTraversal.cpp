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
        int level = q.size();
        ret.push_back(vector <int> ());
        for (int i = 0; i < level; ++i) {
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






/*
 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        bool flag = true; //从左向右打印为true，从右向左打印为false
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> out;
            TreeNode* node;
            while (n>0)
            {
                if (flag) // 前取后放：从左向右打印，所以从前边取，后边放入
                {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);  // 下一层顺序存放至尾
                    if (node->right)
                        q.push_back(node->right);
                }
                else  //后取前放： 从右向左，从后边取，前边放入
                {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);  // 下一层逆序存放至首
                    if (node->left)
                        q.push_front(node->left);
                }
                out.push_back(node->val);
                n--;
            }
            flag = !flag;
            res.push_back(out);
        }
        return res;
    }
};

