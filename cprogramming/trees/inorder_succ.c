#include "bst.h"

int inorder_succ(struct BSTnode *root, int val)
{
	if (root == NULL)
		return -1;
	int ret = -1;
	while (root && root->data != val) {
		if (root->data > val) {
			ret = root->data;
			root = root->left;
		} else {
			root = root->right;
		}
	}
	if (root == NULL)
		return -1;

	if (root) {
		if (root->right)
			return min(root->right);
		else
			return ret;
	}
	return -1;
}
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
	root->left = create_node(3);
	root->right = create_node(8);
	root->left->left = create_node(1);
	root->left->left->right = create_node(2);
	root->right->left = create_node(7);
	root->right->left->left = create_node(6);
	root->right->right = create_node(10);
	root->right->right->left = create_node(9);
	root->right->right->right = create_node(11);
	//printf("Inorder Succ:%d.\n",get_inorder_succ(root, root->right));
	int i = 0;
	for (i = 0; i < 13; i++) {
		printf("Inorder Succ of %d :%d\n", i, inorder_succ(root, i));
	}
}
