#include "linkedlist.h"


void reverse_iterative(struct node **head)
{
	struct node *current = *head;
	struct node *prev = NULL, *next = NULL;
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void reverse_recursive(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *result = (*head)->next;
	if (result == NULL)
		return ;
	reverse_recursive(&result);
	(*head)->next->next = *head;
	(*head)->next = NULL;
	*head = result;
}

struct node *reverse_rec(struct node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct node *result = reverse_rec(head->next);
	head->next->next = head;
	head->next = NULL;
	return result;

}

