#include "tree.h"

int is_complete_binary_tree_util(struct Tnode *root, int cur_level, int *max_level, int max_level2)
{
	if (root == NULL) {
		if (cur_level == *max_level)
			return 1;
		if (cur_level == max_level2) {
			*max_level = max_level2;
			return 1;
		}
		return 0;
	}
	return is_complete_binary_tree_util(root->left, cur_level+1, max_level, max_level2) &&
	       is_complete_binary_tree_util(root->right, cur_level+1, max_level, max_level2);
}

int is_complete_binary_tree(struct Tnode *root)
{
	int h = height(root);
	int max_level = h;
	return is_complete_binary_tree_util(root, 0, &max_level, h-1);
}

int main()
{
	struct Tnode *root = create_node(5);
	root->right = create_node(6);
	root->left = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(7);
//	root->left->left->left = create_node(1);
	printf("is complete : %d\n", is_complete_binary_tree(root));
	return 0;
}
