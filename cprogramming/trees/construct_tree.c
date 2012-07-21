#include "tree.h"

int find_index(int num, int *arr, int start, int end)
{
	int i =0;
	for (i=start; i<=end; i++)
	{
		if (arr[i] == num)
			return i;
	}
	return -1;

}
struct Tnode *construct_tree_in_pre(int *inorder, int *preorder,
				    int in_start, int in_end, int *pre)
{
	if (in_start > in_end)
		return NULL;
	struct Tnode *root = create_node(preorder[*pre]);
	int in_index = find_index(preorder[*pre], inorder, in_start, in_end);
	*pre = (*pre)+1;
	if (in_index == -1) {
		printf("The given arrays are not proper\n");
		return NULL;
	}

	root->left = construct_tree_in_pre(inorder, preorder, in_start,
						in_index-1, pre);
	root->right = construct_tree_in_pre(inorder, preorder, in_index+1,
						in_end, pre);
	return root;
}

struct Tnode *construct_tree_in_post(int *inorder, int *postorder,
				     int in_start, int in_end, int *post)
{
	if (in_start > in_end)
		return NULL;
	struct Tnode *root = create_node(postorder[*post]);
	int in_index = find_index(postorder[*post], inorder, in_start, in_end);
	*post = (*post) - 1;
	if (in_index == -1) {
		printf("The given arrays are not proper.\n");
		return NULL;
	}
	root->right = construct_tree_in_post(inorder, postorder, in_index+1,
						in_end, post);
	root->left = construct_tree_in_post(inorder, postorder, in_start,
						in_index -1, post);

	return root;
}

int main()
{
	int inorder[] = {4, 2, 5, 1, 6, 3};
	int preorder[] = {1, 2, 4, 5, 3, 6};
	int postorder[] = {4, 5, 2, 6, 3, 1};
	int pre = 0;
	struct Tnode *root = construct_tree_in_pre(inorder, preorder, 0, 5, &pre);
	printf("Inorder: ");
	print_inorder(root);
	printf("\n");

	printf("Preorder: ");
	print_preorder(root);
	printf("\n");

	printf("Postorder: ");
	print_postorder(root);
	printf("\n");

	int post = 5;
	struct Tnode *root1 = construct_tree_in_post(inorder, postorder, 0, 5, &post);
	printf("Inorder: ");
	print_inorder(root1);
	printf("\n");

	printf("Preorder: ");
	print_preorder(root1);
	printf("\n");

	printf("Postorder: ");
	print_postorder(root1);
	printf("\n");


}
