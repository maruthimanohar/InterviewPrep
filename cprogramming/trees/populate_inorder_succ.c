#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct BSTnode {
	int data;
	struct BSTnode *left;
	struct BSTnode *right;
	struct BSTnode *next;
};

struct BSTnode *create_node(int data)
{
	struct BSTnode *new_node = (struct BSTnode *)malloc(sizeof(struct BSTnode));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void print_inorder(struct BSTnode *root)
{
	if (root == NULL)
		return;
	print_inorder(root->left);
	printf("%d,",root->data);
	print_inorder(root->right);
}

void populate_inorder_succ(struct BSTnode *root, struct BSTnode **prev)
{
	if (root == NULL) {
		return;
	}
	populate_inorder_succ(root->left, prev);
	if (*prev) {
		(*prev)->next = root;
		(*prev) = (*prev)->next;
	} else {
		*prev = root;
		(*prev)->next = NULL;
	}
	populate_inorder_succ(root->right, prev);
}

int main()
{
	struct BSTnode *root = NULL;
	root = create_node(4);
	root->left = create_node(2);
	root->left->right = create_node(3);
	root->right = create_node(6);
	root->right->right = create_node(7);
	print_inorder(root);
	printf("\n");
	struct BSTnode *in_start = NULL;
	populate_inorder_succ(root, &in_start);
	in_start = root;
	while (in_start->left != NULL) {
		in_start = in_start->left;
	}
	while(in_start) {
		printf("%d,", in_start->data);
		in_start = in_start->next;
	}
	printf("\n");
}
