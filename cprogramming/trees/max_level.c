#include <stdio.h>
#include "tree.h"
void level_max(struct Tnode *root, int *level, int *explored_level)
{
	if (root == NULL)
		return;
	if (*level > *explored_level) {
		printf("%d\n", root->data);
		*explored_level = *explored_level + 1;
	}
	*level = *level + 1;
	level_max(root->right, level, explored_level);
	level_max(root->left, level, explored_level);
	*level = *level - 1;;
}

int main()
{
	struct Tnode *root = create_node(10);
	root->right = create_node(30);
	root->left = create_node(5);
	root->left->left = create_node(3);
	root->left->right = create_node(6);
	int level = 0;
	int explored_level = -1;
	level_max(root, &level, &explored_level);
}
