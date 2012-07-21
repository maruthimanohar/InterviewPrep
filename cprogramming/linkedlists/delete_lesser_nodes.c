#include "linkedlist.h"
// Given a singly linked list, remove all the nodes which have a greater value on right side.
void delete_lesser_nodes(struct node **head, int *max)
{
	if (*head == NULL)
		return;
	if ((*head)->data < *max)
		*max = (*head)->data;
	delete_lesser_nodes(&((*head)->next), max);
	if ( (*head)->data < *max) {
		struct node *to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
	} else {
		*max = (*head)->data;
	}
	return;
}

int main()
{
	struct node *list = NULL;
//	push(&list, 3);
//	push(&list, 2);
//	push(&list, 6);
//	push(&list, 5);
//	push(&list, 11);
//	push(&list, 10);
//	push(&list, 15);
//	push(&list, 12);

	push(&list, -10);
	push(&list, -20);
	push(&list, -30);
	push(&list, -40);
	push(&list, -50);
	push(&list, -60);
	print_list(list);
	int max = 0;
	delete_lesser_nodes(&list, &max);
	print_list(list);
}
