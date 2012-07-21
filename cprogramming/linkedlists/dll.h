#include <stdio.h>
struct dll {
	int data;
	struct dll* next;
	struct dll* prev;
};
void push(struct dll** head, int data);
void print_list(struct dll* head);
void reverse_list(struct dll** head);
void delete(struct dll** head, struct dll* d_node);
struct dll *find(struct dll* head, int data);
