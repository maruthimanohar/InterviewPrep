#include "tree.h"
#include "../stack/stack.h"

// Tree traversal without recursion
// and without modifying the tree.
// By using stack.
void pre_order_iterative(struct Tnode *root)
{
	if (root == NULL)
		return;
	struct stack st;
	init_stack(&st, 1);
	push(&st,root);
	while(!is_empty(&st)) {
		struct Tnode *cur = (struct Tnode *)pop(&st);
		printf("%d,", cur->data);
		if (cur->right != NULL)
			push(&st, cur->right);
		if (cur->left != NULL)
		push(&st, cur->left);
	}
	printf("\n");
}

void post_order_iterative(struct Tnode *root)
{
	if (root == NULL)
		return;
	struct stack st;
	init_stack(&st, 1);
	push(&st, root);
	struct Tnode *prev = NULL;
	while (!is_empty(&st)) {
		struct Tnode *cur = (struct Tnode *)top(&st);
		if (!prev || prev->left == cur || prev->right == cur) {
			if (cur->left != NULL)
				push(&st, cur->left);
			else if (cur->right != NULL)
				push(&st, cur->right);
			else {
				printf("%d,", cur->data);
				pop(&st);
			}
		} else if(cur->left == prev) {
			if (cur->right != NULL)
				push(&st, cur->right);
			else {
				printf("%d,", cur->data);
				pop(&st);
			}
		} else if (cur->right == prev) {
			printf("%d,", cur->data);
			pop(&st);
		}
		prev = cur;
	}
	printf("\n");
}

void in_order_iterative(struct Tnode *root)
{
	if (root == NULL)
		return;
	struct stack st;
	init_stack(&st, 1);
	push(&st, root);
	struct Tnode *prev = NULL;
	while (!is_empty(&st)) {
		struct Tnode *cur = (struct Tnode *)top(&st);
		if (!prev || prev->left == cur) {
			if (cur->left != NULL)
				push(&st, cur->left);
		} else {
			printf("%d,", cur->data);
			pop(&st);
			if (cur->right != NULL)
				push(&st, cur->right);
		}

		prev = cur;
	}
	printf("\n");
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right = create_node(3);
	root->right->right = create_node(7);
	printf("Pre-order\n");
	print_preorder(root);
	printf("\n");
	pre_order_iterative(root);

	printf("Post-order\n");
	print_postorder(root);
	printf("\n");
	post_order_iterative(root);

	printf("In-order\n");
	print_inorder(root);
	printf("\n");
	in_order_iterative(root);
}
