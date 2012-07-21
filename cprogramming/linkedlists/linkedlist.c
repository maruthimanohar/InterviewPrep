#include "linkedlist.h"

void push(struct node **head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

int pop(struct node **head)
{
	if (*head == NULL) {
		printf("Error: Attempt to pop on an empty list.\n");
		return -1;
	}
	struct node *next_head = (*head)->next;
	int ret = (*head)->data;
	free(*head);
	*head = next_head;
	return ret;
}

int get_nth(struct node *head, int index)
{
	int count = 0;
	while (head != NULL) {
		if (count == index)
			return head->data;
		count = count + 1;
		head = head->next;
	}
	printf("Error : The position requested beyond the end of the list.\n");
	return -1;
}

int length(struct node *head)
{
	int length =0;
	while (head != NULL) {
		length++;
		head = head->next;
	}
	return length;
}

void delete_list(struct node **head)
{
	struct node *current = *head;
	struct node *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
	return;
}

void insertnth(struct node **head, int index, int data)
{
	if (index == 0) {
		push(head, data);
		return;
	}
	int count = 0;
	struct node *current = *head;
	while (current != NULL && count < index-1) {
		current = current->next;
		count++;
	}
	if (current != NULL) {
		push(&(current->next), data);
	}

}

void print_list(struct node *head)
{
	if (!head) {
		printf("The list is null\n");
		return;
	}
	while (head) {
		printf("%d,",head->data);
		head = head->next;
	}
	printf("\n");
}

void sorted_insert(struct node **head, struct node *new_node)
{
	if (*head == NULL || (*head)->data > new_node->data) {
		new_node->next = *head;
		*head = new_node;
		return;
	}
	struct node *current = *head;
	while (current->next && current->next->data < new_node->data) {
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;

}

void insert_sort(struct node **head)
{
	struct node *current = *head;
	struct node *next;
	*head = NULL;
	while (current) {
		next = current->next;
		sorted_insert(head, current);
		current = next;
	}
	return;
}

void split_two(struct node *head, struct node **list1, struct node **list2)
{
	if (head == NULL) {
		*list1 = NULL;
		*list2 = NULL;
	}
	struct node *slow;
	struct node *fast;
	slow = head;
	fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	*list1 = head;
	*list2 = slow->next;
	slow->next = NULL;
}

void remove_duplicates_sorted(struct node *head)
{
	if (head == NULL)
		return;
	while (head->next) {
		if (head->data == head->next->data) {
			struct node *to_delete = head->next;
			head->next = head->next->next;
			free(to_delete);
		} else {
			head = head->next;
		}
	}
}

void remove_duplicates(struct node *head)
{
	if (head == NULL)
		return;
	struct node *ptr1 = head;
	struct node *ptr2 = NULL;
	struct node *to_delete = NULL;
	while (ptr1) {
		ptr2 = ptr1;
		while (ptr2->next) {
			if (ptr1->data == ptr2->next->data) {
				to_delete = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(to_delete);
			} else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

struct node *shuffle_merge_rec(struct node *list1, struct node *list2)
{
	if (list1 == NULL)
		return list2;
	list1->next = shuffle_merge_rec(list2, list1->next);
	return list1;
}

void move_node(struct node **list1, struct node **list2)
{
	if (*list2 == NULL)
		return;
	struct node *new_head = *list2;
	*list2 = (*list2)->next;
	new_head->next = *list1;
	*list1 = new_head;
}

struct node *sort_merge(struct node *list1, struct node *list2)
{
	struct node *result;
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
			move_node(result_ref, &list1);
		} else {
			move_node(result_ref, &list2);
		}
		result_ref = &((*result_ref)->next);
	}
	return result;
}

void reverse_iterative(struct node **head)
{
	struct node *current = *head;
	struct node *prev = NULL, *next = NULL;
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void reverse_recursive(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *result = (*head)->next;
	if (result == NULL)
		return ;
	reverse_recursive(&result);
	(*head)->next->next = *head;
	(*head)->next = NULL;
	*head = result;
}

struct node *reverse_rec(struct node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct node *result = reverse_rec(head->next);
	head->next->next = head;
	head->next = NULL;
	return result;

}

bool is_palin_rec_util(struct node **left, struct node *right)
{
	if (!right)
		return true;
	bool is_palin = is_palin_rec_util(left, right->next);
	if (!is_palin)
		return false;
	if ((*left)->data != right->data)
		return false;
	*left = (*left)->next;
	return true;
}

bool is_palin_rec(struct node *head)
{
	return is_palin_rec_util(&head, head);
}

bool compare_lists(struct node *list1, struct node *list2)
{
	if (!list1 && !list2)
		return true;
	if (!list1 || !list2)
		return false;
	if (list1->data != list2->data)
		return false;
	return compare_lists(list1->next, list2->next);
}

bool is_palin(struct node *head)
{
	if (head == NULL || head->next == NULL)
		return true;
	struct node *slow = head;
	struct node *fast = head->next;
	struct node *prev_to_slow = NULL;
	while (fast && fast->next) {
		prev_to_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (!fast) {
		struct node *second = slow->next;
		prev_to_slow->next = NULL;
		reverse_recursive(&second);
		bool result = compare_lists(head, second);
		reverse_recursive(&second);
		prev_to_slow->next = slow;
		return result;
		// the list is of  odd lenth, should skip the middle element while comparing.

	} else {
		struct node *second = slow->next;
		slow->next = NULL;
		reverse_recursive(&second);
		bool result = compare_lists(head, second);
		reverse_recursive(&second);
		slow->next = second;
		return result;
	}
	return false;
}

void move_last_to_first(struct node **head)
{
	printf("Moving last element to first\n");
	if (*head == NULL || (*head)->next == NULL)
		return;
	struct node *current = *head;
	while (current->next->next) {
		current = current->next;
	}
	current->next->next = *head;
	*head = current->next;
	current->next = NULL;
	return;
}
