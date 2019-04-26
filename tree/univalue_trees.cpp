#include "algo.h"

bool isUnivalueTree(TreeNode *node, int rootVal)
{
	if (node == nullptr)
	{
		return true;
	}

	if (node->val != rootVal)
	{
		return false;
	}

	if (!isUnivalueTree(node->left, rootVal))
	{
		return false;
	}

	if (!isUnivalueTree(node->right, rootVal))
	{
		return false;
	}
	return true;
}

int countUniValueTrees(TreeNode *root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return isUnivalueTree(root, root->val) + countUniValueTrees(root->left) + countUniValueTrees(root->right);
}

int main()
{
}
