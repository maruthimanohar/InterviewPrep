#include "tree.h"

int is_bst_util(struct Tnode *root, struct Tnode **prev)
{
	if (root == NULL)
		return 1;
	if (!is_bst_util(root->left, prev))
		return 0;
	if (*prev && (*prev)->data > root->data)
		return 0;
	*prev = root;
	return is_bst_util(root->right, prev);

}

int is_bst(struct Tnode *root)
{
	struct Tnode *prev = NULL;
	return is_bst_util(root, &prev);
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(2);
	root->right = create_node(1);
	root->right = create_node(4);
	root->right->left = create_node(3);
	root->right->right = create_node(5);
	printf("is_bst : %d\n",is_bst(root));
}
