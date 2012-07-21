#include "bst.h"

int main()
{
	struct BSTnode *root = NULL;
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	print_inorder(root);
	printf("\n");
	print_preorder(root);
	printf("\n");
	print_postorder(root);
	printf("\n");
	printf("size : %d\n", size(root));
	printf("num_leaf_nodes :%d\n", num_leaf_nodes(root));
	struct BSTnode *root1 = NULL;
	root1 = insert(root1, 1);
	root1 = insert(root1, 3);
	root1 = insert(root1, 2);

	printf("is_identical:%d\n",is_identical(root, root1));
}
