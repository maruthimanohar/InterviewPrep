#include <limits.h>
#include "tree.h"

int largest_bst_util(struct Tnode *root, int *max_size, int *min, int *max, int *is_bst)
{
	if (root == NULL) {
		*is_bst = 1;
		return 0;
	}
	int left_min, left_max;
	*is_bst = 0;
	*min = INT_MAX;
	*max = INT_MIN;

	int left_bst = 0, right_bst = 0;

	int left_size = largest_bst_util(root->left, max_size, min, max, is_bst);
	left_min = *min;
	left_max = *max;
	if (*is_bst && left_max <= root->data) {
		left_bst = 1;
	}

	*is_bst = 0;
	*min = INT_MAX;
	*max = INT_MIN;

	int right_size = largest_bst_util(root->right, max_size, min, max, is_bst);
	if (*is_bst && *min >= root->data) {
		right_bst = 1;
	}
	if (left_min < *min)
		*min = left_min;
	if (root->data < *min)
		*min = root->data;

	if (left_max > *max)
		*max = left_max;
	if (root->data > *max)
		*max = root->data;

	if (left_bst && right_bst) {
		*is_bst = 1;
		if (left_size + right_size + 1 > *max_size )
			*max_size = left_size + right_size + 1;
		return left_size + right_size + 1;
	} else {
		*is_bst = 0;
		return 0;
	}
}

int largest_bst(struct Tnode *root)
{
	int max_size = 0;
	int min = INT_MAX;
	int max = INT_MIN;
	int is_bst = 0;
	largest_bst_util(root, &max_size, &min, &max, &is_bst);
	return max_size;
}

int main()
{
	struct Tnode *root = create_node(50);
	root->left = create_node(10);
	root->right = create_node(60);
	root->left->left = create_node(5);
	root->left->right = create_node(20);
	root->right->left = create_node(55);
	root->right->right = create_node(70);
	root->right->left->left = create_node(45);
	root->right->right->left = create_node(65);
	root->right->right->right = create_node(80);
	printf("Largest BST : %d\n",largest_bst(root));
}
