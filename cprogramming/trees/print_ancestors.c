#include "tree.h"

int print_ancestors(struct Tnode *root, int val)
{
	if (root == NULL)
		return 0;
	if (root->data == val)
		return 1;
	if (print_ancestors(root->left, val) ||
			print_ancestors(root->right, val)) {
		printf("%d,",root->data);
		return 1;
	}
	return 0;
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->left->left->left = create_node(7);
	print_ancestors(root, 7);
	printf("\n");
}
