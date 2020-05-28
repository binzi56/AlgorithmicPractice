//
//  Demo4_1_MaximumDepthOfBinaryTree.hpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/2/20.
//  Copyright © 2019 personal. All rights reserved.
//

#ifndef Demo4_1_MaximumDepthOfBinaryTree_hpp
#define Demo4_1_MaximumDepthOfBinaryTree_hpp

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root);

#endif /* Demo4_1_MaximumDepthOfBinaryTree_hpp */
