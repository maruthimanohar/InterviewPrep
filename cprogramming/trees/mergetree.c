#include "tree.h"
int getNext(struct Tnode** cur,int* set ){
	int k=0;
	*set=0;
	while (*cur) {
		if ((*cur)->left) {
			struct Tnode *p=(*cur)->left;
			while (p->right && (p->right != *cur))
				p=p->right;
			if (!p->right) {
				p->right=*cur;
				*cur=(*cur)->left;
			} else {
				p->right=0;
				k=(*cur)->data;
				*set=1;
				*cur=(*cur)->right;
				return k;
			}
		} else {
			k=(*cur)->data;
			*set=1;
			*cur=(*cur)->right;
			return k;
		}
	}
}

void mergeTree(struct Tnode *T1, struct Tnode *T2){
	struct Tnode *cur1=T1, *cur2=T2;
	int sametree = (cur1 == cur2);
	int set1=0,set2=0;
	int trigger1=1, trigger2=(sametree?0:1);
	int k1=0,k2=0;
	while (trigger1 || trigger2){
		if (trigger1)
			k1=getNext(&cur1,&set1);
		if (trigger2)
			k2=getNext(&cur2,&set2);

		if (set1 && set2) {
			if (k1<k2) {
				printf(" %d ", k1);
				trigger1=1;
				trigger2=0;
			} else {
				printf(" %d ", k2);
				trigger1=0;
				trigger2=1;
			}
		} else if(set1) {
			printf(" %d ", k1);
			if(sametree)
				printf(" %d ", k1);
			trigger1=1;
			trigger2=0;
		} else if(set2) {
			printf(" %d ", k2);
			trigger1=0;
			trigger2=1;
		} else {
			trigger1=0;
			trigger2=0;
		}
	}
	printf("\n");
}

int main()
{
	struct Tnode *root1 = create_node(4);
	root1->left = create_node(2);
	root1->right = create_node(7);
	struct Tnode *root2 = create_node(9);
	root2->left = create_node(3);
	mergeTree(root1, root2);
}
