#include "queue.h"

struct Qnode *create_qnode(void *data)
{
	struct Qnode *new_node = (struct Qnode *)malloc(sizeof(struct Qnode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void enqueue(struct Qnode **q, void *data)
{
	struct Qnode *qnode = create_qnode(data);
	if (*q == NULL) {
		*q = qnode;
		return;
	}
	struct Qnode *current = *q;
	while(current->next != NULL)
		current = current->next;
	current->next = qnode;

}

void *dequeue(struct Qnode **q)
{
	if (*q == NULL)
		return NULL;
	struct Qnode *head = *q;
	*q = (*q)->next;
	void *result = head->data;
	free(head);
	return result;
}

int is_empty(struct Qnode *q)
{
	if (*q == NULL)
		return 1;
	return -1;
}
