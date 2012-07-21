#include "tree.h"

#define MAX(a,b) ( (a > b) ? a : b)

int diameter_util(struct Tnode *root, int *height)
{
	if (root == NULL) {
		*height = 0;
		return 0;
	}
	int lheight = 0;
	int rheight = 0;
	int l_diameter = diameter_util(root->left, &lheight);
	int r_diameter = diameter_util(root->right, &rheight);
	*height = MAX(lheight, rheight) + 1;
	return MAX((lheight + rheight + 1), MAX(l_diameter, r_diameter));
}

int diameter(struct Tnode *root)
{
	int height =0;
	return diameter_util(root, &height);
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->left->right->left = create_node(6);
	printf("Diameter : %d\nn", diameter(root));
}
