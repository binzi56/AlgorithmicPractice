#  二叉树的序列化与反序列化

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 
```
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
```
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

解法:
```
class Solution {
public:

     string serialize(TreeNode* root) {
        string ret;
        dfs(root,ret);
        return ret;
    }

    void dfs(TreeNode* root,string& ret){
        if(root == nullptr) {
            ret.append("#,");
            return;
        }

        ret.append(to_string(root->val)).append(",");
        dfs(root->left,ret);
        dfs(root->right,ret);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return rdfs(data,i);
    }

    TreeNode* rdfs(const string& data,int& i){
        if(data[i] == '#') {
            i += 2;
            return nullptr;
        }

        int next = i;
        while(data[next] != ',')
            next++;
        int val = stoi(data.substr(i,next-i));
        auto ret = new TreeNode(val);
        i = next+1;

        ret->left = rdfs(data,i);
        ret->right = rdfs(data,i);

        return ret;
    }
};
```
