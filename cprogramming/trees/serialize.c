#include <stdio.h>
#include "tree.h"
#include "../stack/stack.h"


struct Tnode *deserialize_rec(int *arr, int size, int *cur_pos)
{
	if (*cur_pos >= size)
		return NULL;
	if (arr[*cur_pos] == -1) {
		(*cur_pos)++;
		return NULL;
	}
	int val = arr[*cur_pos];
	struct Tnode *root = create_node(val);
	(*cur_pos)++;
	root->left = deserialize_rec(arr, size, cur_pos);
	root->right = deserialize_rec(arr, size, cur_pos);
	return root;
}

struct Tnode *deserialize(int *arr, int size)
{
	if (size == 0)
		return NULL;
	struct stack st1, st2;
	init_stack(&st1, 10);
	init_stack(&st2, 10);
	int cur_pos = 0;
	struct Tnode *root = create_node(arr[cur_pos++]);
	push(&st1, root);
	while (!is_empty(&st1)) {
		if ( top(&st1) != top(&st2)) {
			struct Tnode *cur_node = (struct Tnode *)top(&st1);
			int val = arr[cur_pos++];
			printf("val1:%d\n", val);
			struct Tnode *new_node = NULL;
			if (val != -1) {
				new_node = create_node(val);
				printf("putting %d as left child of %d\n", new_node->data, cur_node->data);
			}
			cur_node->left = new_node;
			push(&st2, cur_node);
			if (new_node) {
				printf("pushing %d on to stack1\n", new_node->data);
				push(&st1, new_node);
			}
			print_inorder(root);
			printf("\n");

		} else {
			struct Tnode *cur_node = (struct Tnode *)top(&st1);
			int val = arr[cur_pos++];
			printf("val2:%d\n", val);
			struct Tnode *new_node = NULL;
			if (val != -1) {
				new_node = create_node(val);
				printf("puting %d as right child of %d\n", new_node->data, cur_node->data);
			}
			cur_node->right = new_node;
			pop(&st1);
			pop(&st2);
			if (new_node) {
				printf("pushing %d on to stack2\n", new_node->data);
				push(&st1, cur_node);
			}
			print_inorder(root);
			printf("\n");
		}
	}
	print_inorder(root);
	printf("\n");
	return root;
}

void serialize(struct Tnode *root, int *arr, int *size)
{
	if (root == NULL) {
		*size = 0;
		return;
	}

	int cur_size = 0;
	struct stack st;
	init_stack(&st, 10);
	push(&st, root);
	while (!is_empty(&st)) {
		struct Tnode *cur_node = pop(&st);
		*(arr + cur_size++) = cur_node->data;
		if (cur_node->right)
			push(&st, cur_node->right);
		else
			*(arr + cur_size++) = -1;
		if (cur_node->left)
			push(&st,cur_node->left);
		else
			*(arr + cur_size++) = -1;

	}
	*size = cur_size;
}

int main()
{
	struct Tnode *root = create_node(5);
	root->left = create_node(4);
	root->right = create_node(6);
	int *serial = (int *)malloc(sizeof(int) * 10);
	int size = 10;
	serialize(root, serial, &size);
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("%d,", serial[i]);
	}
	printf("\n");

//	struct Tnode *result = deserialize(serial, size);
	int cur_pos = 0;
	struct Tnode *result = deserialize_rec(serial, size, &cur_pos);
	print_preorder(result);
	printf("\n");
	print_inorder(result);
	printf("\n");
}
