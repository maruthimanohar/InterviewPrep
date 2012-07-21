#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data);
int pop(struct node **head);
int get_nth(struct node *head, int index);
void delete_list(struct node **head);
int length(struct node *head);
void insertnth(struct node **head, int index, int data);
void print_list(struct node *head);
void reverse_iterative(struct node **head);
void reverse_recursive(struct node **head);
struct node *reverse_rec(struct node *head);

void append(struct node **head1, struct node **head2);
void split_two(struct node *head, struct node **list1, struct node **list2);
bool is_palin(struct node *head);
bool is_palin_rec(struct node *head);
void move_last_to_first(struct node **head);

void sorted_insert(struct node **head, struct node *new_node);
void insert_sort(struct node **head);

void remove_duplicates(struct node *head);
void remove_duplicates_sorted(struct node *head);
struct node *shuffle_merge_rec(struct node *list1, struct node *list2);
struct node *sort_merge(struct node *list1, struct node *list2);


#endif
