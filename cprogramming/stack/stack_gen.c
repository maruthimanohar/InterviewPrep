#include <stdlib.h>
#include <string.h>
#include "stack_gen.h"

int init_stack(struct stack *st, int max_size, int elem_size)
{
	if (st == NULL)
		return 0;
	st->arr = (void *)malloc(elem_size * max_size);
	if (st->arr == NULL)
		return 0;
	st->elem_size = elem_size;
	st->max_size = max_size;
	st->cur_size = -1;
	return 1;
}

int push(struct stack *st, void *elem)
{
	if (st == NULL)
		return 0;
	if (is_full(st)) {
		return 0;
	}
	st->cur_size += 1;
	memcpy(((char *)(st->arr)) + (st->elem_size * st->cur_size), elem, st->elem_size);
	return 1;
}

int pop(struct stack *st, void *elem)
{
	if (st == NULL || elem == NULL)
		return 0;
	if (is_empty(st)) {
		return 0;
	}
	memcpy(elem, ((char *)(st->arr)) + (st->elem_size * st->cur_size), st->elem_size);
	st->cur_size -= 1;
}

int is_empty(struct stack *st)
{
	if (st == NULL)
		return 1;
	if (st->cur_size == -1)
		return 1;
	return 0;
}

int is_full(struct stack *st)
{
	if (st == NULL)
		return 0;
	if (st->cur_size == (st->max_size -1))
		return 1;
	return 0;
}
