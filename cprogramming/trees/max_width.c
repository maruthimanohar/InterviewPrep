#include "tree.h"

void max_width_util(struct Tnode *root, int *count_array, int level)
{
	if (root == NULL)
		return;
	count_array[level] = count_array[level] + 1;
	max_width_util(root->left, count_array, level + 1);
	max_width_util(root->right, count_array, level + 1);
}

int max_width(struct Tnode *root) {
	if (root == NULL)
		return 0;
	int i = 0, max = 0;
	int h = height(root);
	int *count_array = (int *)malloc(sizeof(int) * h);
	for (i=0; i < h; i++)
		count_array[i] = 0;
	max_width_util(root, count_array, 0);
	for (i = 0; i < h; i++)
		if (count_array[i] > max)
			max = count_array[i];
	return max;
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->right = create_node(6);
	printf("width : %d\n",max_width(root));
}
