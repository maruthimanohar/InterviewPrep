#include "linkedlist.h"

void seg_even_odd(struct node **head)
{
	struct node *even_list = NULL;
	struct node **even_ref = &even_list;

	struct node *odd_list = NULL;
	struct node **odd_ref = &odd_list;

	struct node *current = *head;
	struct node *temp = NULL;
	while (current) {
		temp = current->next;
		if (current->data %2 == 0) {
			*even_ref = current;
			current->next = NULL;
			even_ref = &((*even_ref)->next);
		} else {
			*odd_ref = current;
			current->next = NULL;
			odd_ref = &((*odd_ref)->next);
		}
		current = temp;
	}
	if (even_list != NULL) {
		*even_ref = odd_list;
	}
	else
		even_list = odd_list;
	*head = even_list;
}

void seg_even_odd_dummy(struct node **head)
{
	struct node even_dummy;
	struct node *even_tail = &(even_dummy);

	struct node odd_dummy;
	struct node *odd_tail = &(odd_dummy);

	struct node *current = *head;
	struct node *temp = NULL;
	while (current) {
		temp = current->next;
		if (current->data % 2 == 0) {
			even_tail->next = current;
			current->next = NULL;
			even_tail = current;
		} else {
			odd_tail->next = current;
			current->next = NULL;
			odd_tail = current;
		}
		current = temp;
	}
	if (even_tail != &(even_dummy))
		even_tail->next = odd_dummy.next;
	else
		even_dummy = odd_dummy;
	*head = even_dummy.next;

}
int main()
{
	struct node *list;
//	push(&list, 4);
	push(&list, 1);
//	push(&list, 6);
	push(&list, 3);
	print_list(list);
	seg_even_odd(&list);
	print_list(list);
}
