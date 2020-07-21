#include<iostream>
#include<stack>
using namespace std;

class BinaryTree
{
   public:
      int val;
      BinaryTree *left,*right;
};

void CreateTree(BinaryTree* &root)
{
    int x;
    cin>>x;
    if(x=='#')
    {
        root=NULL;
    }
    else
    {
        root=new BinaryTree;
        root->val=x;
        CreateTree(root->left);
        CreateTree(root->right);
    }
}

void Preorder(BinaryTree* root)
{
    if(root!=nullptr)
    {
        stack<BinaryTree*> stack1;
        stack1.push(root);
        while (!stack1.empty())
	    {
		  root = stack1.top();
		  cout << root->val;
		  stack1.pop();
		  if (root->right)
		     stack1.push(root->right);
		  if (root->left)
			 stack1.push(root->left);
	    }
	    cout << endl;
    }
}
int main()
{
	BinaryTree* root;
	CreateTree(root);
	Preorder(root);
	return 0;
}