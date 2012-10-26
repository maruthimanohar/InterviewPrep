#include "tree.h"
#include "../stack/stack.h"

int get_next(struct Tnode **root, int *found)
{
	int ret = -1;
	*found = 0;
	while (*root != NULL) {
		if ((*root)->left == NULL)
		{
			ret = (*root)->data;
			*found = 1;
			*root = (*root)->right;
			break;
		}
		else {
			struct Tnode *pre = (*root)->left;
			while (pre->right && pre->right != *root) {
				pre = pre->right;
			}
			if (pre->right == NULL) {
				pre->right = *root;
				*root = (*root)->left;
			} else {
				*root = pre->right;
				pre->right = NULL;
				ret = (*root)->data;
				*found =1;
				(*root) = (*root)->right;
				break;
			}
		}
	}
	return ret;
}

void merge_tree(struct Tnode *root1, struct Tnode *root2)
{
	struct Tnode *cur1 = root1;
	struct Tnode *cur2 = root2;
	int get_first = 1, get_second = 1;
	int found1 = 0, found2 = 0;
	int first = 0, second = 0;

	while (get_first || get_second)
	{
		if (get_first) {
			first = get_next(&cur1, &found1);
		}
		if (get_second)
			second = get_next(&cur2, &found2);
		if (found1 && found2) {
			if (first < second) {
				printf("%d,", first);
				get_first = 1;
				get_second = 0;
			} else {
				printf("%d,", second);
				get_second = 1;
				get_first = 0;
			}
		} else if (found1) {
			printf("%d,", first);
			get_first = 1;
			get_second = 0;
		} else if (found2) {
			printf("%d,", second);
			get_first = 0;
			get_second = 1;
		} else {
			get_first = 0;
			get_second = 0;
		}

	}
	printf("\n");
}

int get_next_stack(struct stack *st, struct Tnode **prev, int *found)
{
	if (is_empty(st)) {
		*found = 0;
		return -1;
	}
	int result = -1;
	while(1) {
		struct Tnode *cur = (struct Tnode *)top(st);
		if (!*prev || (*prev)->left == cur) {
			if (cur->left)
				push(st, cur->left);
		} else {
			result = cur->data;
			pop(st);
			if (cur->right)
				push(st, cur->right);
		}
		*prev = cur;
		if (result != -1) {
			*found = 1;
			break;
		}
	}
	return result;
}

void merge_tree_stack(struct Tnode *root1, struct Tnode *root2)
{
	struct Tnode *cur1 = root1;
	struct Tnode *cur2 = root2;
	struct Tnode *prev1 = NULL;
	struct Tnode *prev2 = NULL;
	struct stack st1, st2;
	init_stack(&st1, 10);
	init_stack(&st2, 10);
	push(&st1, cur1);
	push(&st2, cur2);
	int first = 0, second = 0;
	int get_first = 1, get_second = 1;
	int found1 = 0, found2 = 0;
	while(1) {
		if (get_first) {
			first = get_next_stack(&st1, &prev1, &found1);
		}
		if (get_second) {
			second = get_next_stack(&st2, &prev2, &found2);
		}
		if (found1 && found2) {
			if (first < second) {
				printf("%d ", first);
				get_first = 1;
				get_second = 0;
			} else {
				printf("%d ", second);
				get_first = 0;
				get_second = 1;
			}
		} else if (found1) {
			printf("%d ", first);
			get_first = 1;
			get_second = 0;
		} else if (found2) {
			printf("%d ", second);
			get_first = 0;
			get_second = 1;
		} else {
			break;
		}
	}
	printf("\n");
}

int main()
{
	struct Tnode *root1 = create_node(4);
	root1->left = create_node(2);
	root1->right = create_node(7);
	struct Tnode *root2 = create_node(9);
	root2->left = create_node(3);
	merge_tree_stack(root1, root2);

}
