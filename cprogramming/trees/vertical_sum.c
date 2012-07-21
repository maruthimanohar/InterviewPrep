#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Tnode {
	int data;
	struct Tnode *left;
	struct Tnode *right;
};

struct dll {
	int data;
	struct dll* next;
	struct dll* prev;
};

struct Tnode *create_node(int data)
{
	struct Tnode *new_node = (struct Tnode *)malloc(sizeof(struct Tnode));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void vertical_sum_util(struct Tnode *root, struct dll* current)
{
	printf("%d\n",root->data);
	if (root->right) {
		printf("%d has right\n", root->data);
		if (!(current->next)) {
			printf("%d has no next, creating one.\n", root->data);
			current->next = (struct dll*)malloc(sizeof(struct dll*));
			current->next->data = 0;
			current->next->next = NULL;
			current->next->prev = current;
		} else {
			printf("%d has next already with data %d\n", root->data, current->next->data);
		}
		current->next->data += root->right->data;

		struct dll *tmp = current;
		printf("Printing next list\n");
		while (tmp) {
			printf("%d\n",tmp->data);
			tmp = tmp->next;
		}
		printf("\n Printed list\n");
		tmp = current;
		printf("Printing previous list\n");
		while (tmp) {
			printf("%d\n",tmp->data);
			tmp = tmp->prev;
			if (tmp) {
				printf("Prev is not null\n");
			}
		}
		printf("\n Printed list\n");


		printf("%d calling its right.\n", root->data);
		vertical_sum_util(root->right, current->next);
	}
	if (root->left) {
		printf("%d has left\n", root->data);
		if (!(current->prev)) {
			printf("%d has no previous, creating one.\n", root->data);
			current->prev = (struct dll*)malloc(sizeof(struct dll*));
			current->prev->data = 0;
			current->prev->next = current;
			current->prev->prev = NULL;
		} else {
			printf("%d has previous with data \n",root->data);
		}
		printf("%d calling its left.\n", root->data);
		current->prev->data += root->left->data;
		vertical_sum_util(root->left, current->prev);

	}
	printf("%d done with left and right\n", root->data);
}

struct dll *vertical_sum(struct Tnode *root)
{
	if (root == NULL)
		return NULL;
	struct dll *result = (struct dll*)malloc(sizeof(struct dll*));
	result->data = 0;
	result->data += root->data;
	result->next = NULL;
	result->prev = NULL;
	vertical_sum_util(root, result);
	while (result->prev)
		result = result->prev;
	return result;
}

int main()
{
	struct Tnode *root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->right->right = create_node(7);
	struct dll* result = vertical_sum(root);
	while(result) {
		printf("%d,",result->data);
		result = result->next;
	}
	printf("\n");
}
