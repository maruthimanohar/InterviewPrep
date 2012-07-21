#include "tree.h"

void mirror(struct Tnode *root)
{
	if (root == NULL)
		return;
	mirror(root->left);
	mirror(root->right);

	struct Tnode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

int main()
{
	struct Tnode *root = NULL;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);

	print_inorder(root);
	printf("\n");
	print_preorder(root);
	printf("\n");
	print_postorder(root);
	printf("\n");
	mirror(root);

	printf("Mirrored the tree\n");
	print_inorder(root);
	printf("\n");
	print_preorder(root);
	printf("\n");
	print_postorder(root);
	printf("\n");

}
