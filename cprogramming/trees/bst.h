#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct BSTnode {
	int data;
	struct BSTnode *left;
	struct BSTnode *right;
};

struct BSTnode *insert(struct BSTnode *root, int data);
void print_inorder(struct BSTnode *root);
void print_postorder(struct BSTnode *root);
void print_preorder(struct BSTnode *root);
struct BSTnode *create_node(int data);

int min(struct BSTnode *root);

int size(struct BSTnode *root);

int num_leaf_nodes(struct BSTnode *root);

int is_identical(struct BSTnode *root1, struct BSTnode *root2);
#endif
