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
    int maxDepth(TreeNode* root) {
        if(!root)   
           return 0;
        vector<TreeNode*> nodes{root};
        int dep = 1;
        vector<int> depth{dep};
        while(!nodes.empty()){
            auto node = nodes[0];
            nodes.erase(nodes.begin());
            dep = depth[0];
            depth.erase(depth.begin());
            if(node->left)
            {
                nodes.push_back(node->left);
                depth.push_back(dep + 1);
            }
            if(node->right)
            {
                nodes.push_back(node->right);
                depth.push_back(dep + 1);
            }
        }
        return dep;
    }
};