// Write a function to connect all the adjacent nodes at the same level in a binary tree.
// Structure of the given Binary Tree node is like following.

// Initially, all the nextRight pointers point to garbage values.
// Your function should set these pointers to point next right for each node.
// You can use only constant extra space.

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *next_right;
};

struct node *get_next_right(struct node *root)
{
	struct node *next_node = root->next_right;
	while (next_node != NULL) {
		if (next_node->left != NULL)
			return next_node->left;
		if (next_node->right != NULL)
			return next_node->right;
		next_node = next_node->next_right;
	}
	return NULL;
}

void connect_rec(struct node *root)
{
	if (root == NULL)
		return;
	// first connect the children of the next right.
	connect(root->next_right);
	// get the next node to which last child of the current node should point to.
	struct node *next_node = get_next_right(root);
	// if there is a right child to the current node, make its right child's nextptr
	// point to the next node and make the right child as next node.
	if (root->right) {
		root->right->next_right = next_node;
		next_node = root->right;
	}
	// similarly for the left child.
	if (root->left) {
		root->left->next_right = next_node;
		next_node = root->left;
	}
	// call recursively at the next level.
	connect_rec(next_node);
}

void connect_iter(struct node *root)
{
	if (root == NULL)
		return;
	while (root != NULL) {
		struct node *cur_node = root;
		while (cur_node != NULL) {
			struct node *next_node = get_next_right(cur_node);
			if (cur_node->right != NULL) {
				cur_node->right->next_right = next_node;
				next_node = cur_node->right;
			}
			if (cur_node->left != NULL) {
				cur_node->left->next_right = next_node;
				next_node = cur_node->left;
			}
			cur_node = cur_node->next_right;
		}
		if (root->left)
			root = root->left;
		else if (root->right)
			root = root->right;
		else
			root = get_next_right(root);
	}
}

struct node *create_node(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->next_right = NULL;
	return new_node;
}

int main()
{
	struct node *root = create_node(10);
	root->left = create_node(8);
	root->right = create_node(2);
	root->left->left = create_node(3);
	root->right->right = create_node(90);
	connect_iter(root);
	printf("Following are populated nextRight pointers in the tree "
			"(-1 is printed if there is no nextRight) \n");
	printf("nextRight of %d is %d \n", root->data,
			root->next_right? root->next_right->data: -1);
	printf("nextRight of %d is %d \n", root->left->data,
			root->left->next_right? root->left->next_right->data: -1);
	printf("nextRight of %d is %d \n", root->right->data,
			root->right->next_right? root->right->next_right->data: -1);
	printf("nextRight of %d is %d \n", root->left->left->data,
			root->left->left->next_right? root->left->left->next_right->data: -1);
	printf("nextRight of %d is %d \n", root->right->right->data,
			root->right->right->next_right? root->right->right->next_right->data: -1);

	return 0;
}
