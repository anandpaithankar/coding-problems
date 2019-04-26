#include "algo.h"

struct TreeNode
{
	int data;
	TreeNode *left = nullptr, *right = nullptr;
};

struct DeepestNode
{
	int depth;
	TreeNode *node;
	bool operator>(const DeepestNode &n)
	{
		return depth > n.depth;
	}
}; 

DeepestNode depth(TreeNode *root)
{
	if (root == nullptr)
	{
		return DeepestNode{0, root};
	}

	auto left = depth(root->left);
	auto right = depth(root->right);
	if (left > right) {
		left.depth++;
		return left;
	} else {
		right.depth++;
		return right;
	}
}

TreeNode *deepestNode(TreeNode *root)
{
	if (root == nullptr)
	{
		return root;
	}

	// go down the left subtree and calculate the depth of the deepest node
	auto left = depth(root->left);

	// go down the right subtree and calculate the depth of the deepest node
	auto right = depth(root->right);

	if (left > right) {
		return left.node;
	} else {
		return right.node;
	}

}

int main()
{
	TreeNode *root = new TreeNode{1, new TreeNode{2, new TreeNode{3, nullptr}, nullptr}, new TreeNode{4, nullptr}};
	auto n = deepestNode(root);
	std::cout << n;
}