#include "linkedlist.h"

void delete(struct node **head, int elem)
{
	if (*head == NULL)
		return;
	struct node **cur_ref = head;
	while (*cur_ref) {
		if ((*cur_ref)->data == elem) {
			struct node *to_delete = *cur_ref;
			cur_ref = &((*cur_ref)->next);
			free(to_delete);
		} else {
			cur_ref = &((*cur_ref)->next);
		}
	}
}

int main()
{
	struct node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	print_list(head);
	delete(&head, 1);
	print_list(head);
}
