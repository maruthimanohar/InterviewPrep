#include "tree.h"

int is_child_sum_property(struct Tnode *root)
{
	if (root == NULL)
		return 1;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int left_data = 0, right_data = 0;
	if (root->left)
		left_data = root->left->data;
	if (root->right)
		right_data = root->right->data;
	return (root->data == (left_data + right_data)) &&
		is_child_sum_property(root->left) &&
		is_child_sum_property(root->right);
}

void fix_sum(struct Tnode *root, int diff)
{
	if (root->left) {
		root->left->data = root->left->data + diff;
		fix_sum(root->left, diff);
	} else if (root->right) {
		root->right->data = root->right->data + diff;
		fix_sum(root->right, diff);
	}
}

void convert_child_sum_property(struct Tnode *root)
{
	if (root == NULL)
		return;
	convert_child_sum_property(root->left);
	convert_child_sum_property(root->right);
	int left_data = 0, right_data = 0;
	if (root->left)
		left_data = root->left->data;
	if (root->right)
		right_data = root->right->data;
	int diff = root->data - (left_data + right_data);
	if (diff < 0) {
		root->data = root->data + (-diff);
	} else if (diff >0) {
		fix_sum(root, diff);
	}
	return;

}
int main()
{
	struct Tnode *root = NULL;
	root = create_node(12);
	root->left = create_node(8);
	root->right = create_node(2);
	root->left->left = create_node(3);
	root->left->left->right = create_node(1);
	root->left->right = create_node(5);
	root->right->left = create_node(1);
	print_inorder(root);
	printf("\n");
	print_preorder(root);
	printf("\n");
	printf("Is Child Sum Property : %d\n",is_child_sum_property(root));
	convert_child_sum_property(root);
	print_inorder(root);
	printf("\n");
	print_preorder(root);
	printf("\n");
	printf("Is Child Sum Property : %d\n",is_child_sum_property(root));

}
