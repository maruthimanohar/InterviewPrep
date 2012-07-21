#include "tree.h"
#define MAX(a, b) ( (a > b) ? a : b )
struct Tnode *create_node(int data)
{
	struct Tnode *node = (struct Tnode *)malloc(sizeof(struct Tnode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void print_inorder(struct Tnode *root)
{
	if (root == NULL)
		return;
	print_inorder(root->left);
	printf("%d,",root->data);
	print_inorder(root->right);
}

void print_postorder(struct Tnode *root)
{
	if (root == NULL)
		return;
	print_postorder(root->left);
	print_postorder(root->right);
	printf("%d,", root->data);
}

void print_preorder(struct Tnode *root)
{
	if (root == NULL)
		return;
	printf("%d,", root->data);
	print_preorder(root->left);
	print_preorder(root->right);
}

void delete(struct Tnode *root)
{
	if (root == NULL)
		return;
	delete(root->left);
	delete(root->right);
	free(root);
}

int size(struct Tnode *root)
{
	if (root == NULL)
		return 0;
	return size(root->left) + size(root->right) + 1;
}


int height(struct Tnode *root)
{
	if (root == NULL)
		return 0;
	int lheight = height(root->left);
	int rheight = height(root->right);
	return MAX(lheight, rheight) + 1;
}

int num_leaf_nodes(struct Tnode *root)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return num_leaf_nodes(root->left) + num_leaf_nodes(root->right);
}

int is_identical(struct Tnode *root1, struct Tnode *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 == NULL || root2 == NULL)
		return 0;
	return ( (root1->data == root2->data) &&
		is_identical(root1->left, root2->left) &&
		is_identical(root1->right, root2->right) );
}
