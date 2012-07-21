#include "bst.h"

struct BSTnode *create_node(int data)
{
	struct BSTnode *node = (struct BSTnode *)malloc(sizeof(struct BSTnode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct BSTnode *insert(struct BSTnode *root, int data)
{
	if (root == NULL)
		return create_node(data);
	if (data > root->data) {
		root->right =  insert(root->right, data);
	} else {
		root->left = insert(root->left, data);
	}
	return root;
}

void print_inorder(struct BSTnode *root)
{
	if (root == NULL)
		return;
	print_inorder(root->left);
	printf("%d,",root->data);
	print_inorder(root->right);
}

void print_postorder(struct BSTnode *root)
{
	if (root == NULL)
		return;
	print_postorder(root->left);
	print_postorder(root->right);
	printf("%d,", root->data);
}

void print_preorder(struct BSTnode *root)
{
	if (root == NULL)
		return;
	printf("%d,", root->data);
	print_preorder(root->left);
	print_preorder(root->right);
}

int min(struct BSTnode *root)
{
	if (root == NULL)
		return -1;
	struct BSTnode *current = root;
	while(current->left) {
		current = current->left;
	}
	return current->data;
}

int size(struct BSTnode *root)
{
	if (root == NULL)
		return 0;
	return size(root->left) + size(root->right) + 1;
}

int num_leaf_nodes(struct BSTnode *root)
{
	if(root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return num_leaf_nodes(root->left) + num_leaf_nodes(root->right);
}

int is_identical(struct BSTnode *root1, struct BSTnode *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 == NULL || root2 == NULL)
		return 0;
	return ( (root1->data == root2->data) &&
		is_identical(root1->left, root2->left) &&
		is_identical(root1->right, root2->right) );
}
