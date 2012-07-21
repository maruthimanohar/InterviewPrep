#include "linkedlist.h"
void delete_alternate(struct node *head)
{
	while(head) {
		if (head->next) {
			struct node *to_delete = head->next;
			head->next = head->next->next;
			free(to_delete);
		}
		head = head->next;
	}
}

void delete_alternate_rec(struct node *head)
{
	if (head == NULL || head->next == NULL)
		return;
	struct node *to_delete = head->next;
	head->next = head->next->next;
	free(to_delete);
	delete_alternate_rec(head->next);
}

int main()
{
	struct node *list;
//	push(&list, 1);
//	push(&list, 2);
//	push(&list, 3);
//	push(&list, 4);
//	push(&list, 5);
	print_list(list);
	delete_alternate_rec(list);
	print_list(list);
}
