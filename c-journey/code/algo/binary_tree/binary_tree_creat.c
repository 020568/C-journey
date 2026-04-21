#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

struct TreeNode* newTreeNode(int x)
{
	struct TreeNode* node=(struct TreeNode*)malloc(sizeof(TreeNode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}

// You can construct a binary tree like this:
struct TreeNode* root=newTreeNode(1);
root->left=newTreeNode(2);
root->right=newTreeNode(3);
root->left->left=newTreeNode(4);
root->left->right=newTreeNode(5);



