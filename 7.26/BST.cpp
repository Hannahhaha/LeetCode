#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
         return isValidBST(root, NULL, NULL);
    }
    //对于左子树找最大值，对于右子树找最小值，然后判断左边最大值小于根节点，右子树最小值大于根节点
    //递归判断
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) 
     {
        if (root == NULL) {
            return true;
        }

        if (min != NULL && root->val <= min->val || max!= NULL && root->val >= max->val) {
            return false;
        }
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};