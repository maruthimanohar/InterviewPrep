#include <stdio.h>
#include "tree.h"
int k_largest(struct Tnode *root, int *k) {
	if (root == NULL)
		return -1;
	int val = k_largest(root->right, k);
	if (*k == 0)
		return val;
	*k = *k -1;
	if (*k == 0)
		return root->data;
	return k_largest(root->left, k);

}
int main()
{
	struct Tnode * root = create_node(6);
	root->left = create_node(3);
	root->right = create_node(8);
	root->left->left = create_node(1);
	root->left->left->right = create_node(2);
	root->right->left = create_node(7);
	root->right->right = create_node(10);
	root->right->right->left = create_node(9);
	root->right->right->right = create_node(12);
	int k = 0;
	int i =0;
	for (i = 0; i < 12 ; i++) {
		k = i;
		printf("%d\n", k_largest(root,&k));
	}
}
