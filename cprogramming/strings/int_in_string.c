#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *next;
};

struct node *create_new_node(int data)
{
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void append(struct node **head, struct node *new_node)
{
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	struct node *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return;
}

void print_list(struct node *head)
{
	while (head != NULL)
	{
		printf("%d,", head->data);
		head = head->next;
	}
	printf("\n");
}

int char_to_int(char a)
{
	return atoi(&a);
}

struct node *
get_ints(char *str)
{
	if (str == NULL)
		return NULL;
	int len = strlen(str);
	struct node *result = NULL;
	int cur_pos = 0;
	int has_int = 0;
	int cur_int = 0;
	while (*(str + cur_pos))
	{
		printf("%c\n", *(str + cur_pos));
		if (*(str + cur_pos) >= '0' &&
		    *(str + cur_pos) <= '9') {
			cur_int = cur_int * 10 + char_to_int(*(str + cur_pos));
			has_int = 1;
			cur_pos++;
			continue;
		}
		if (has_int) {
			struct node *next_node = create_new_node(cur_int);
			append(&result, next_node);
			has_int = 0;
			cur_int = 0;
		}
		cur_pos++;
	}
	if (has_int) {
		struct node *next_node = create_new_node(cur_int);
		append(&result, next_node);
	}
	return result;
}

main()
{
	char *version = "ESX Server 5.0.0p1 build 22-1029";
	printf("%s\n", version);
	struct node *list = get_ints(version);
	print_list(list);
}
