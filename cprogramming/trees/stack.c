#include "stack.h"

struct Snode *create_snode(void *data)
{
	struct Snode *new_node = (struct Snode *)malloc(sizeof(struct Snode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void push(struct Snode **s, void *data)
{
    struct Snode *snode = create_snode(data);
    snode->next = *s;
    *s = snode;
    return;
}

void *pop(struct Snode **s)
{
	if (*s == NULL)
		return NULL;
	struct Snode *head = *s;
	*s = (*s)->next;
	void *result = head->data;
	free(head);
	return result;
}

int is_empty_stack(struct Snode *s)
{
	if (s == NULL)
		return 1;
	return 0;
}
