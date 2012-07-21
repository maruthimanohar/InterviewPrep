#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
struct dll* create_new_node(int data)
{
	struct dll* new_node = (struct dll*)malloc(sizeof(struct dll));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev= NULL;
	return new_node;
}

void push(struct dll** head, int data)
{
	printf("Pushing Data : %d\n",data);
	struct dll* new_node = create_new_node(data);
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
	return;
}

void print_list(struct dll* head)
{
	printf("Printing Forward!!\n");
	struct dll *last = head;
	while (head) {
		last = head;
		printf("%d,",head->data);
		head = head->next;
	}
	printf("\n");
	printf("Priting Backward!!\n");
	while(last) {
		printf("%d,",last->data);
		last = last->prev;
	}
	printf("\n");
}

void reverse_list(struct dll** head)
{
	printf("Reversiong the list\n");
	struct dll* current = *head;
	struct dll* previous = NULL;
	while (current) {
		previous = current->prev;
		current->prev = current->next;
		current->next = previous;
		current = current->prev;
	}
	if (previous)
		*head = previous->prev;
}

void delete(struct dll** head, struct dll* d_node)
{
	if (*head == NULL || d_node == NULL) {
		printf("In delete: either head or node passed is NULL\n");
		return;
	}
	printf("Delete : deleting the node %d\n",d_node->data);
	if (*head == d_node)
		*head = d_node->next;
	if (d_node->next)
		d_node->next->prev = d_node->prev;
	if (d_node->prev)
		d_node->prev->next = d_node->next;
	free(d_node);
}

struct dll *find(struct dll* head, int data)
{
	while(head) {
		if (head->data == data)
		       return head;
		head = head->next;
	}
	printf("Could not find node with data :%d\n",data);
	return NULL;
}
