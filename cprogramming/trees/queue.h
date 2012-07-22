#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct Qnode {
	void *data;
	struct Qnode *next;
};

void enqueue(struct Qnode **q, void *data);
void *dequeue(struct Qnode **q);
int is_empty(struct Qnode *q);
#endif
