#include "tree.h"
int sum_to_leaf(struct Tnode *root, int sum)
{
	if (root == NULL && sum == 0 )
		return 1;
	if (root == NULL)
		return 0;

	int sub_sum = sum - root->data;
	if (sub_sum == 0 && root->left == NULL && root->right == NULL)
		return 1;
	if (root->left && sum_to_leaf(root->left, sub_sum))
		return 1;
	if (root->right && sum_to_leaf(root->right, sub_sum))
		return 1;
	return 0;
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(10);
	root->left = create_node(8);
	root->right = create_node(2);
	root->left->left = create_node(3);
	root->left->right = create_node(5);
	root->right->left = create_node(2);
	printf("Has sum : %d\n", sum_to_leaf(root, 23));
}
