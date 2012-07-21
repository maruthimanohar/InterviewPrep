#include "tree.h"

#define MAX(a,b) ( (a > b) ? a : b )

int is_balanced_util(struct Tnode *root, int *height)
{
	if (root == NULL) {
		*height = 0;
		return 1;
	}
	int lheight = 0, rheight = 0;
	int is_left_balanced = is_balanced_util(root->left, &lheight);
	int is_right_balanced = is_balanced_util(root->right, &rheight);
	*height = MAX(lheight, rheight) +1;

	if ((lheight - rheight) > 1 || (rheight - lheight) > 1)
		return 0;
	return is_left_balanced && is_right_balanced;
}

int is_balanced(struct Tnode *root)
{
	int height = 0;
	return is_balanced_util(root, &height);
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	printf("Is Balanced Tree : %d\n", is_balanced(root));
}
