#include "linkedlist.h"

void move_node_new(struct node **head_ref, struct node **list)
{
	*head_ref = *list;
	*list = (*list)->next;
	head_ref = &((*head_ref)->next);
}
void split_alternate(struct node *head, struct node **first, struct node **second)
{
	if (head == NULL)
		return;
	struct node *first_result = NULL;
	struct node *second_result = NULL;
	struct node **first_ref = &first_result;
	struct node **second_ref = &second_result;



	struct node *current = head;
	while(current) {
		move_node(first_ref, &current);
		first_ref = &((*first_ref)->next);
		if (current) {
			move_node(second_ref, &current);
			second_ref = &((*second_ref)->next);
		}

	}
	*first = first_result;
	*second = second_result;

}

int main()
{
	struct node *list = NULL;
	struct node *first = NULL;
	struct node *second = NULL;
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	push(&list, 4);
	print_list(list);
	split_alternate(list, &first, &second);
	print_list(first);
	print_list(second);
}
