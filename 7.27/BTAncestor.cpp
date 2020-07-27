#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL || p == root || q == root)
        {
            return root;
        }
        //分别查找左子树和右子树，pq在左子树返回left，pq在右子树返回right.
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        //如果左子树为空返回right，如果右左子树为空返回left，最后返回目标root.
        if(left == NULL)
        {
            return right;
        }
        else if(right == NULL)
        {
            return left;
        }
        else
            return root;
    }
};