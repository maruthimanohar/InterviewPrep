#include "tree.h"

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
	printf("size : %d\n",size(root));
	printf("height: %d\n", height(root));
	printf("Num of leaf nodes : %d\n",num_leaf_nodes(root));
	printf("is_identical:%d\n",is_identical(root, root));
	delete(root);
	printf("deleted the tree\n");
}
