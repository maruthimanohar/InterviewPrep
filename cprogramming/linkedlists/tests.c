#include "linkedlist.h"
void insertnth_test() 
{
	struct node *head =  NULL;
	insertnth(&head, 0, 13);
	print_list(head);
	insertnth(&head, 1, 4);
	print_list(head);
	insertnth(&head, 1, 4);
	print_list(head);
	insertnth(&head, 1, 5);
	print_list(head);
	insertnth(&head, 1, 5);
	print_list(head);
	insertnth(&head, 2, 10);
	print_list(head);
	insertnth(&head, 4, 20);
	print_list(head);
	insert_sort(&head);
	print_list(head);
	remove_duplicates(head);
	print_list(head);

}

void split_test()
{
	struct node *head =  NULL;
	printf("get 1st %d\n",get_nth(head, 1));
	insertnth(&head, 0, 13);
	print_list(head);
	printf("get 0th %d\n",get_nth(head, 0));
	printf("get 1st %d\n",get_nth(head, 1));
	insertnth(&head, 1, 4);
	print_list(head);
	printf("get 0th %d\n",get_nth(head, 0));
	printf("get 1st %d\n",get_nth(head, 1));
	printf("get 1st %d\n",get_nth(head, 2));
/*	insertnth(&head, 1, 5);
	print_list(head);
	insertnth(&head, 2, 10);
	print_list(head);
	insertnth(&head, 4, 20);*/
	print_list(head);
	reverse_iterative(&head);
	print_list(head);
	head = reverse_rec(head);
	print_list(head);
/*	struct node *first = NULL, *second = NULL;
	split_two(head, &first, &second);
	print_list(first);
	print_list(second);
	first->next = NULL;
	struct node *shuffle_merge = shuffle_merge_rec(first, second);
	print_list(shuffle_merge);
*/
}
void print_palin(struct node *head)
{
	if (is_palin_rec(head))
		printf("The list is palindrome\n");
	else
		printf("The list is not palindrome\n");
}
void palin_test()
{
	struct node *head = NULL;
	print_list(head);
	print_palin(head);
	push(&head, 1);
	print_list(head);
	print_palin(head);
	push(&head, 1);
	print_list(head);
	print_palin(head);
	pop(&head);
	push(&head, 2);
	print_list(head);
	print_palin(head);
	push(&head, 1);
	print_list(head);
	print_palin(head);
}

void move_last_to_first_test()
{
	struct node *head = NULL;
	print_list(head);
	move_last_to_first(&head);
	print_list(head);
	push(&head,1);
	print_list(head);
	move_last_to_first(&head);
	print_list(head);
	push(&head,2);
	print_list(head);
	move_last_to_first(&head);
	print_list(head);
	push(&head,3);
	print_list(head);
	move_last_to_first(&head);
	print_list(head);
	push(&head,4);
	print_list(head);
	move_last_to_first(&head);
	print_list(head);
}

int main() {
//	insertnth_test();
//	split_test();
//	palin_test();
	move_last_to_first_test();
}
