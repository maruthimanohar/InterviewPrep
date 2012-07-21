#include "dll.h"
insert_test(struct dll **head)
{
	push(head, 1);
	push(head, 5);
	push(head, 3);
//	push(head, 4);
}

delete_test(struct dll **head)
{
	delete(head, find(*head, 3));
}
int main()
{
	struct dll* head;
	insert_test(&head);
	print_list(head);
//	reverse_list(&head);
	delete_test(&head);
	print_list(head);
}
