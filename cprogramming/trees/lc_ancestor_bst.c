#include "bst.h"

// Given the values of two nodes in a *binary search tree*,
// write a c program to find the lowest common ancestor.
// You may assume that both values already exist in the tree.
struct BSTnode * lca_bst(struct BSTnode *root, int data1, int data2)
{
	if (root == NULL)
		return NULL;
	if (root->data == data1 || root->data == data2)
		return NULL;
	while(root) {
		if (root->right && (root->right->data == data1 || root->right->data == data2))
			return root;
		if (root->left && (root->left->data == data1 || root->right->data == data2))
			return root;
		if (data1 < root->data  && data2 < root->data)
			root = root->left;
		else if (data1 > root->data && data2 > root->data)
			root = root->right;
		else
			return root;
	}
	return root;
}

int main()
{
	struct BSTnode *root = NULL;
	root = create_node(2);
	root->left = create_node(1);
	root->right = create_node(4);
	root->right->left = create_node(3);
	root->right->right = create_node(5);
	struct BSTnode *result = lca_bst(root, 2, 5);
	if (result)
		printf("%d\n", result->data);
	else
		printf("No Least common ancestor found\n");
}
