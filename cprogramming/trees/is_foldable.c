#include "tree.h"

int is_foldable_util(struct Tnode *first, struct Tnode *second)
{
	if (first == NULL && second == NULL)
		return 1;
	if (first == NULL || second == NULL)
		return 0;
	return is_foldable_util(first->left, second->right) &&
		is_foldable_util(first->right, second->left);
}

int is_foldable(struct Tnode *root)
{
	if (root == NULL)
		return 1;
	return is_foldable_util(root->left, root->right);
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->right = create_node(4);
	root->right->left = create_node(5);
	printf("Is foldable : %d\n",is_foldable(root));
}
