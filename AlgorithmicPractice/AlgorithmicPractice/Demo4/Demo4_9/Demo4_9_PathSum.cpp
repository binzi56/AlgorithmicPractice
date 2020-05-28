//
//  Demo4_9_PathSum.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/26.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo4_9_PathSum.hpp"

//DFS
bool hasPathSum(TreeNode* root, int sum) {
    if(!root)   return false;
    sum -= root -> val;
    if((!root -> left) && (!root -> right)) return sum == 0;
    return hasPathSum(root -> left, sum) || hasPathSum(root -> right, sum);
}

