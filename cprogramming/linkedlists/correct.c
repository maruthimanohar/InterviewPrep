#include <stdio.h>
#include "linkedlist.h"

void correct_list(struct node **list)
{
	if (*list == NULL)
		return;
	struct node *head = *list;
	struct node *first = NULL, *second = NULL, *third = NULL;

	while (head->next && head->next->data > head->data) {
		first = head;
		head = head->next;
	}
	while (head->next && head->next->data < head->data) {
		head = head->next;
	}
	second = head;
	struct node *rest = NULL;
	if (head)
		rest = head->next;
	if (first) {
		if (second) {
			second->next = NULL;
		}
		struct node *tail = first->next;
		first->next = reverse_rec(first->next);
		tail->next = rest;
	} else if (second) {
		second->next = NULL;
		struct node *tail = *list;
		*list = reverse_rec(*list);
		tail->next = rest;
	}
}

int main()
{
	struct node *list = NULL;
	//push(&list, 8);
	//push(&list, 7);
	push(&list, 4);
	push(&list, 5);
	push(&list, 6);
	push(&list, 3);
	push(&list, 2);
	//push(&list, 1);
	print_list(list);
	correct_list(&list);
	print_list(list);

}
