#include "algo.h"

void iterativePostOrder(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}

	std::stack<TreeNode *> st;
	std::set<TreeNode *> visited;

	TreeNode *current = root;
	st.push(current);

	while (!st.empty())
	{
		auto *t = st.top();
		if (t->right && visited.count(t->right) == 0) {
			st.push(t->right);
			visited.insert(t->right);
			t->right = nullptr;
		}
			

		if (t->left && visited.count(t->left) == 0) {
			st.push(t->left);
			visited.insert(t->left);
			t->left = nullptr;
		}


		if (t->left == nullptr && t->right == nullptr) {
			std::cout << t->val << " ";
			st.pop();
		}
	}
}

int main()
{
	TreeNode *root = new TreeNode{1, new TreeNode{2, nullptr, nullptr}, 
	new TreeNode{4, new TreeNode{5, nullptr}}};
	iterativePostOrder(root);
}