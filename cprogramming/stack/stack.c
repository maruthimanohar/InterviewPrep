#include <stdlib.h>
#include "stack.h"

void init_stack(struct stack *st, int size)
{
	st->cur_size = 0;
	st->size = size;
	st->list = (void **)malloc(sizeof(void *) * size);
}

void push(struct stack *st, void *elem)
{
	if (st->cur_size == st->size) {
		int size = st->size * 2;
		if (st->size == size)
			size = size + 1;
		st->list = (void *)realloc(st->list, sizeof(void *) * (size));
		st->size = size;
	}
	st->list[st->cur_size++] = elem;
}

void *pop(struct stack *st)
{
	if (st->cur_size == 0)
		return NULL;
	return st->list[--st->cur_size];
}

void *top(struct stack *st)
{
	if (st->cur_size == 0)
		return NULL;
	return st->list[st->cur_size-1];
}

int is_empty(struct stack *st)
{
	if (st->cur_size == 0)
		return 1;
	return 0;
}
