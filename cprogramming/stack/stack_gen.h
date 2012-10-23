#ifndef STACK_H
#define STACH_H

struct stack {
	int max_size;
	int elem_size;
	int cur_size;
	void *arr;
};

int init_stack(struct stack *st, int max_size, int elem_size);
int push(struct stack *st, void *elem);
int pop(struct stack *st, void *elem);
int is_empty(struct stack *st);
int is_full(struct stack *st);

#endif
