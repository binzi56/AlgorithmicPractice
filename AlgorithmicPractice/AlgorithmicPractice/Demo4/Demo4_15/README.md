# 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：
```
     5
    / \
   2   6
  / \
 1   3
```
示例 1：
```
输入: [1,6,3,2,5]
输出: false
```
示例 2：
```
输入: [1,3,2,6,5]
输出: true
```

提示：
* 数组长度 <= 1000

解法:
```
//二叉搜索树特征，左子树所有节点的值<根节点的值<右子树节点的值
递归检查根节点是否将序列划分为左右子树

class Solution {
    bool helper(vector<int>& post,int lo, int hi){
        if(lo >= hi) return true; //单节点或空节点返回true
        int root = post[hi]; //后序遍历序列最后的值为根节点的值
        int l = lo;
        while(l<hi && post[l]<root) 
            l++; //遍历左子树(值小于根)，左子树序列post[lo, l);
        int r = l;
        while(r<hi && post[r]>root)
            r++; //遍历右子树(值大于根)，右子树序列post[l, r);
        if(r != hi) return false;//若未将post[l, hi)遍历完，则非后序遍历序列 返回false
        return helper(post, lo, l-1) && helper(post, l, hi-1); //递归检查左右子树
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder,0,postorder.size()-1);
    }
};
```

