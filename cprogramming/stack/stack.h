#ifndef STACK_H
#define STACH_H

struct stack {
	int cur_size;
	int size;
	void **list;
};

void init_stack(struct stack *st, int size);
void push(struct stack *st, void *elem);
void *pop(struct stack *st);
void *top(struct stack *st);
int is_empty(struct stack *st);
#endif
