#include "tree.h"

// Morris Traversal
void pre_order_iterative(struct Tnode *root)
{
	struct Tnode *current = root;
	struct Tnode *pre = NULL;
	while (current != NULL) {
		if (current->left == NULL) {
			printf("%d,", current->data);
			current = current->right;
		} else {
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;
			if (pre->right == NULL) {
				pre->right = current;
				printf("%d,", current->data);
				current = current->left;
			} else {
				pre->right = NULL;
				current = current->right;
			}
		}
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
	pre_order_iterative(root);
	print_preorder(root);
	printf("\n");
}
