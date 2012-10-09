#include <stdio.h>
#include "linkedlist.h"

struct node *intersect(struct node *list1, struct node *list2)
{
	struct node dummy;
	struct node *tail = &dummy;
	while (list1 && list2)
	{
		if (list1->data < list2->data)
			list1 = list1->next;
		else if (list1->data > list2->data)
			list2 = list2->next;
		else {
			tail->next = create_node(list1->data);
			tail = tail->next;
			list1 = list1->next;
			list2 = list2->next;
			}
	}
	return dummy.next;
}

int main()
{
	struct node *list1 = NULL;
	struct node *list2 = NULL;
	push(&list1, 6);
	push(&list1, 4);
	push(&list1, 3);
	push(&list1, 2);
	push(&list1, 1);

	push(&list2, 8);
	push(&list2, 6);
	push(&list2, 4);
	push(&list2, 2);
	struct node *list3 = intersect(list1, list2);
	print_list(list3);
}
