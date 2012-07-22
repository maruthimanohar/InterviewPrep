#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct Tnode {
	int data;
	struct Tnode *left;
	struct Tnode *right;
};

struct Tnode *create_node(int data);
void print_inorder(struct Tnode *root);
void print_postorder(struct Tnode *root);
void print_preorder(struct Tnode *root);

int size(struct Tnode *root);
int height(struct Tnode *root);
int num_leaf_nodes(struct Tnode *root);
void delete(struct Tnode *root);

int is_identical(struct Tnode *root1, struct Tnode *root2);
#endif
