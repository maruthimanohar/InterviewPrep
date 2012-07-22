#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct Snode {
	void *data;
	struct Snode *next;
};

void push(struct Snode **s, void *data);
void *pop(struct Snode **s);
int is_empty_stack(struct Snode *s);
#endif
