#include "linkedlist.h"

struct node *reverse_grp(struct node *head, int k)
{
	struct node *prev = NULL;
	struct node *next = NULL;
	struct node *current = head;
	while (current && k >0) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		k--;
	}
	head->next = reverse_grp(current, k);
	return head;
}

int main()
{
	struct node *list = NULL;
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	print_list(list);
	list = reverse_grp(list, 1);
	print_list(list);
}
