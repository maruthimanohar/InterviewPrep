#include <stdio.h>
#include "tree.h"

void postorder_iterative(struct Tnode *root)
{
	struct Tnode *pre;
	while (root != NULL) {
		if (root->left) {
			pre = root->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			if (pre->right == current) {
				pre->right = NULL;
				
			} else {
				pre->right = current;
				current = pre;
			}
		}
	}
}
int main()
{
}
