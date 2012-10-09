#include "linkedlist.h"
// Given a singly linked list, remove all the nodes which have a greater value on right side.
// leader elements
void delete_lesser_nodes(struct node **head, int *max)
{
	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
	{
		*max = (*head)->data;
		return;
	}

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
#define sll struct node
void deleteNode(sll **h)
{
	sll *prev = NULL;
	sll *cur = *h ;
	sll *forward = cur->next ;
	sll *f ;

	while( forward != NULL)
	{
		if ( cur->data < forward->data )
		{
			if ( cur == *h )
			{

				*h = cur->next ;
			}
			else
			{
				prev->next = forward ;
			}
			prev = cur ;
			f = cur ;
			cur = cur->next;
			forward = forward->next ;
			free(f);
			continue;
		}
		prev = cur ;
		cur = cur->next ;
		forward = forward->next ;
	}

}

int main()
{
	struct node *list = NULL;
	push(&list, 3);
	push(&list, 2);
	push(&list, 6);
	push(&list, 5);
	push(&list, 11);
	push(&list, 10);
	push(&list, 15);
	push(&list, 12);

/*	push(&list, -10);
	push(&list, -20);
	push(&list, -30);
	push(&list, -40);
	push(&list, -50);
	push(&list, 60);
	*/
	print_list(list);
	int max = 0;
	//delete_lesser_nodes(&list, &max);
	deleteNode(&list);
	print_list(list);
}
