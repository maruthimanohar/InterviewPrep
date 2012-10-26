#include "linkedlist.h"

struct node *reverse_grp(struct node *head, int k)
{
	if (head == NULL)
		return NULL;
	struct node *prev = NULL;
	struct node *next = NULL;
	struct node *current = head;
	int i = k;
	while (current && i > 0) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		i--;
	}
	head->next = reverse_grp(current, k);
	return prev;
}

int main()
{
	struct node *list = NULL;
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	push(&list, 4);
	push(&list, 5);
	push(&list, 6);
	print_list(list);
	list = reverse_grp(list, 2);
	print_list(list);
}
