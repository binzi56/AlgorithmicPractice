//
//  Demo4_7_BinaryTreeLevelOrderTraversal.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_7_BinaryTreeLevelOrderTraversal.hpp"


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int q = (int)queue.size();
        vector<int> tmp;
        for (int i = 0; i < q; i++) {
            tmp.push_back(queue.front()->val);
            if (queue.front()->left) {
                queue.push(queue.front()->left);
            }
            if (queue.front()->right) {
                queue.push(queue.front()->right);
            }
            queue.pop();
        }
        res.push_back(tmp);
    }
    return res;
}
