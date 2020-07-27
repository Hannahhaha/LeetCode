#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root==NULL || root==p || root==q) 
        {
            return root;
        } 
        //如果P,Q都大于root,那么两个目标节点都在右子树，递归调用lowestCommonAncestor查找右子树，直到分叉
        //如果P,Q都小于root,那么两个目标节点都在左子树，递归调用lowestCommonAncestor查找左子树，直到分叉
        //只有当pq分叉，一个在左子树，一个在右子树，最后return root。

        if (root -> val < p -> val && root -> val < q -> val) 
        {
            return lowestCommonAncestor(root -> right, p, q);
        } 

        else if(root -> val > p -> val && root -> val > q -> val) 
        {
            return lowestCommonAncestor(root -> left, p, q);
        }
        
        return root;
    
    }
};