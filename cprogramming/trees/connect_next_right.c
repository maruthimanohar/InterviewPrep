// Write a function to connect all the adjacent nodes at the same level in a binary tree.
// Structure of the given Binary Tree node is like following.

// struct node {
//	int data;
//	struct node* left;
//	struct node* right;
//	struct node* nextRight;
// }
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
	struct node *temp = root->next_right;
	while (temp != NULL) {
		if (temp->left != NULL)
			return temp->left;
		if (temp->right != NULL)
			return temp->right;
		temp = temp->next_right;
	}
	return NULL;
}

void connect_rec(struct node *root)
{
	if (root == NULL)
		return;
	printf("looking at : %d\n", root->data);
	connect(root->next_right);
	struct node *next_node = get_next_right(root);
	if (root->right) {
		printf("%d has right, setting its right \n", root->data);
		root->right->next_right = next_node;
		next_node = root->right;
	}
	if (root->left) {
		printf("%d has left, setting its right \n", root->data);
		root->left->next_right = next_node;
		next_node = root->left;
	}
	connect_rec(next_node);
}

void connect_iter(struct node *root)
{
	if (root == NULL)
		return;
	while (root != NULL) {
		struct node *temp = root;
		while (temp != NULL) {
			struct node *next_node = get_next_right(temp);
			if (temp->right != NULL) {
				temp->right->next_right = next_node;
				next_node = temp->right;
			}
			if (temp->left != NULL) {
				temp->left->next_right = next_node;
				next_node = temp->left;
			}
			temp = temp->next_right;
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

	getchar();
	return 0;
}
