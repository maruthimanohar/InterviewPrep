#include "tree.h"
// Morris Traversal
void in_order_iterative(struct Tnode *root)
{
	struct Tnode *current = root;
	struct Tnode *pre = NULL;
	printf("Inorder Traversal:");
	while (current != NULL) {
		// if there is no left node, print the current node and advance to the right.
		if (current->left == NULL) {
			printf("%d,",current->data);
			current = current->right;
		} else {
			pre = current->left;
			// find the predecessor the current node in the left subtree.
			while (pre->right != NULL && pre->right != current) {
				pre = pre->right;
			}
			// if we need to print the left subtree,
			// the predecessor right will be null, so make it point to current node.
			// and advance to the left subtree.
			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			} else {
				// if we already printed the left subtree, the predecessors right
				// will point to current. so make it nul.
				// print the current node and advance to right.
				pre->right = NULL;
				printf("%d,",current->data);
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
	in_order_iterative(root);

}
