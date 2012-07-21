#include "bst.h"

int get_inorder_succ(struct BSTnode *root, struct BSTnode *n)
{
	if (n == NULL)
		return -1;
	if (n->right)
		return min(n->right);

	int ret = -1;
	while(root) {
		if (n->data < root->data) {
			ret = root->data;
			root = root->left;
		} else if (n->data > root->data) {
			root = root->right;
		} else {
			break;
		}
	}

	return ret;
}

int main()
{
	struct BSTnode *root = NULL;
	root = create_node(5);
	root->left = create_node(4);
	root->right = create_node(7);
	printf("Inorder Succ:%d.\n",get_inorder_succ(root, root->right));
}
