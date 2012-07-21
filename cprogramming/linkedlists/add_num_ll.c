#include "linkedlist.h"

struct node *add_list_util(struct node *head1, struct node *head2,
			int length1, int length2, int *carry)
{
	int sum = 0;
	*carry = 0;
	struct node *rest = NULL;
	if (length1 == 0 && length2 == 0) {
		*carry = 0;
		return NULL;
	}

	if (length1 > length2) {
		rest = add_list_util(head1->next, head2, length1 - 1, length2, carry);
		sum = head1->data + *carry;
	} else if(length1 < length2) {
		rest = add_list_util(head1, head2->next, length1, length2 - 1, carry);
		sum = head2->data + *carry;
	} else {
		rest = add_list_util(head1->next, head2->next, length1 - 1, length2 -1, carry);
		sum = head1->data + head2->data + *carry;
	}
	struct node *current = (struct node *)malloc(sizeof(struct node));
	current->data = sum%10;
	current->next = rest;
	*carry = sum/10;
	return current;
}

struct node *add_list(struct node *list1, struct node *list2)
{
	int length1 = length(list1);
	int length2 = length(list2);
	int carry = 0;
	struct node *result = add_list_util(list1, list2, length1, length2, &carry);
	while (carry > 0) {
		struct node *new_result = (struct node*)malloc(sizeof(struct node));
		new_result->data = carry%10;
		carry = carry/10;
		new_result->next = result;
		result = new_result;
	}
	return result;
}

int main()
{
	struct node *list1;
	struct node *list2;
	push(&list1, 9);
	push(&list1, 9);
	push(&list1, 9);
	print_list(list1);
	push(&list2, 9);
	push(&list2, 9);
	push(&list2, 9);
	print_list(list2);
	struct node *sum = add_list(list1, list2);
	print_list(sum);
}
