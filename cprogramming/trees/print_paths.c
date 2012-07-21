#include "tree.h"

void print_path(int *path, int pathlen)
{
	int i=0;
	for (i=0; i<pathlen; i++) {
		printf("%d,",path[i]);
	}
	printf("\n");
}

void print_paths_util(struct Tnode *root, int *path, int pathlen)
{
	if (root == NULL)
		return;
	path[pathlen] = root->data;
	pathlen = pathlen + 1;
	if (root->left == NULL && root->right == NULL) {
		print_path(path, pathlen);
		return;
	}
	print_paths_util(root->left, path, pathlen);
	print_paths_util(root->right, path, pathlen);
}

void print_paths(struct Tnode *root)
{
	if (root == NULL)
		return;
	int h = height(root);
	int *path = (int *)malloc(sizeof(int)*h);
	print_paths_util(root, path, 0);
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
	printf("Printing paths:\n");
	print_paths(root);
}
