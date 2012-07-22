#include "tree.h"
#include "queue.h"
#include "stack.h"

void print_levelorder(struct Tnode *root)
{
    printf("Printing level order\n");
    if (root == NULL)
        return;
    struct Qnode *queue = NULL;
    enqueue(&queue, (void *)root);
    while (! is_empty(queue)) {
        struct Tnode *curr = (struct Tnode *)dequeue(&queue);
        printf("%d,", curr->data);
        if (curr->left)
            enqueue(&queue, (void *)(curr->left));
        if (curr->right)
            enqueue(&queue, (void *)(curr->right));
    }
    printf("\n");
}

void print_sprialorder(struct Tnode *root)
{
    printf("Printing spiral order\n");
    if (root == NULL)
        return;
    struct Snode *stack1 = NULL, *stack2 = NULL;
    int level = 1;
    printf("Pushing data :%d\n", root->data);
    push(&stack1, root);
    while (!is_empty_stack(stack1) || !is_empty_stack(stack2)) {
        while (!is_empty_stack(stack1)) {
            struct Tnode *curr = (struct Tnode *)pop(&stack1);
            printf("%d,", curr->data);
            if (curr->left != NULL)
                push(&stack2, curr->left);
            if (curr->right != NULL)
                push(&stack2, curr->right);
        }
        while(!is_empty_stack(stack2)) {
            struct Tnode *curr = (struct Tnode *)pop(&stack2);
            printf("%d,", curr->data);
            if (curr->right != NULL)
                push(&stack1, curr->right);
            if (curr->left != NULL)
                push(&stack1, curr->left);
        }
    }
    printf("\n");
}

int main()
{
    struct Tnode *root = create_node(5);
    root->left = create_node(3);
    root->right = create_node(8);
    root->left->left = create_node(2);
    root->left->right = create_node(4);
    root->right->left = create_node(7);
    root->right->right = create_node(9);
    root->left->left->left = create_node(1);
    root->right->left->left = create_node(6);
    print_levelorder(root);
    print_sprialorder(root);
}

