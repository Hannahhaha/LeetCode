#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        helper(root, 0, level);

        return level;
    }

    void helper(TreeNode* root, int n, vector<vector<int>>& level) {
        if (root == NULL) {
            return;
        }
        if (level.size() > n) {
            level[n].push_back(root->val);
        } else {
            vector<int> tmp;
            tmp.push_back(root->val);
            level.push_back(tmp);
        }
        helper(root->left, n+1, level);
        helper(root->right, n+1, level);
    }
};