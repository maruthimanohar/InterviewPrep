#include "bst.h"

struct BSTnode *merge(struct BSTnode *list1, struct BSTnode *list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	list1->left->right = list2;
	list2->left->right = list1;
	struct BSTnode *temp = list1->left;
	list1->left = list2->left;
	list2->left = temp;
	return list1;
}

struct BSTnode *bst_to_dll_circular(struct BSTnode *root)
{
	if (root == NULL)
		return NULL;
	struct BSTnode *prev = bst_to_dll_circular(root->left);
	struct BSTnode *next = bst_to_dll_circular(root->right);

	root->left = root;
	root->right = root;

	struct BSTnode *result = merge(prev, root);
	result = merge(result, next);
	return result;
}

struct BSTnode *bst_to_dll(struct BSTnode *root)
{
	struct BSTnode *result = bst_to_dll_circular(root);
	if (result) {
		result->left->right = NULL;
		result->left = NULL;
	}
	return result;
}

int get_len(struct BSTnode *head)
{
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->right;
	}
	return len;
}

struct BSTnode *dll_to_bst(struct BSTnode *head)
{
	int len = get_len(head);
	return dll_to_bst(head);
}

int main()
{
	struct BSTnode *root = create_node(4);
	root->left = create_node(2);
	root->right = create_node(5);
	root->left->left = create_node(1);
	root->left->right = create_node(3);
	print_inorder(root);
	printf("\n");
	struct BSTnode *head = bst_to_dll(root);
	while (head != NULL) {
		printf("%d,",head->data);
		head = head->right;
	}
	printf("\n");
}
