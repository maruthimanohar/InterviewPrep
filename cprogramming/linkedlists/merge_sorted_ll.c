#include "linkedlist.h"
struct node *merge_sorted_list(struct node *list1, struct node *list2)
{
	struct node *result = NULL;
	struct node **result_ref = &result;
	while (1) {
		if (list1 == NULL) {
			*result_ref = list2;
			break;
		}
		if (list2 == NULL) {
			*result_ref = list1;
			break;
		}
		if (list1->data < list2->data) {
			*result_ref = list1;
			list1 = list1->next;
			(*result_ref)->next = NULL;
			result_ref = &((*result_ref)->next);
			continue;
		}
		else {
			*result_ref = list2;
			list2 = list2->next;
			(*result_ref)->next = NULL;
			result_ref = &((*result_ref)->next);
			continue;
		}
	}
	return result;
}

struct node *merge_sorted_list_rec(struct node *list1, struct node *list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	if (list1->data < list2->data) {
		list1->next = merge_sorted_list_rec(list1->next, list2);
		return list1;
	}
	list2->next = merge_sorted_list_rec(list1, list2->next);
	return list2;
}

void merge_sort(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *first = NULL;
	struct node *second = NULL;
	split_two(*head, &first, &second);
	merge_sort(&first);
	merge_sort(&second);
	*head = merge_sorted_list(first, second);
}

int main()
{
	struct node *list1 = NULL;
	struct node *list2 = NULL;
	push(&list1, 1);
	push(&list1, 3);
	push(&list1, 3);
	push(&list1, 1);
	print_list(list1);
	merge_sort(&list1);
	print_list(list1);

	push(&list2, 6);
	push(&list2, 6);
	push(&list2, 2);
	print_list(list2);
	struct node *result = merge_sorted_list_rec(list1, list2);


	print_list(result);
}
