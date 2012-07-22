#include "tree.h"

struct Tnode *crotate(struct Tnode *root)
{
    struct Tnode *ret = root->left;
    root->left = ret->right;
    ret->right = root;
    return ret;
}

struct Tnode *acrotate(struct Tnode *root)
{
    struct Tnode *ret = root->right;
    root->right = ret->left;
    ret->left = root;
    return ret;
}

struct Tnode *avl_insert(struct Tnode *root, int data)
{

    if (root == NULL) {
        struct Tnode* new_node = create_node(data);
        return new_node;
    }
    if (data < root->data) {
        root->left = avl_insert(root->left, data);
    } else {
        root->right = avl_insert(root->right, data);
    }
    int l_height = height(root->left);
    int r_height = height(root->right);
//    root->height = max(l_height, r_height) + 1;
    int diff = l_height - r_height;
    if (diff >= 2) {
        if (data < root->left->data) {
            return crotate(root);
        } else {
            root->left = acrotate(root->left);
            return crotate(root);
        }
    } else if (diff <= -2) {
        if (data > root->right->data) {
            return acrotate(root);
        } else {
            root->right = crotate(root->right);
            return acrotate(root);
        }
    }
    return root;
}

int main()
{
    struct Tnode* head;
    printf("inserting 1\n");
    head = avl_insert(head ,1);
    print_preorder(head);
    printf("\n");
    printf("inserting 2\n");
    head = avl_insert(head ,2);
    print_preorder(head);
    printf("\n");
    printf("inserting 3\n");
    head = avl_insert(head ,3);
    print_preorder(head);
    printf("\n");
    printf("inserting 4\n");
    head = avl_insert(head, 4);
    print_preorder(head);
    printf("\n");
    printf("inserting 5\n");
    head = avl_insert(head, 5);
    print_preorder(head);
    printf("\n");
    printf("inserting 6\n");
    head = avl_insert(head, 6);
    print_preorder(head);
    printf("\n");
    printf("inserting 7\n");
    head = avl_insert(head, 7);
    print_preorder(head);
    printf("\n");

    printf("inserting 16\n");
    head = avl_insert(head, 16);
    print_preorder(head);
    printf("\n");

    printf("inserting 15\n");
    head = avl_insert(head, 15);
    print_preorder(head);
    printf("\n");
    printf("inserting 14\n");
    head = avl_insert(head, 14);
    print_preorder(head);
    printf("\n");
    printf("inserting 13\n");
    head = avl_insert(head, 13);
    print_preorder(head);
    printf("\n");
    printf("inserting 12\n");
    head = avl_insert(head, 12);
    print_preorder(head);
    printf("\n");
    printf("inserting 11\n");
    head = avl_insert(head, 11);
    print_preorder(head);
    printf("\n");
    printf("inserting 10\n");
    head = avl_insert(head, 10);
    print_preorder(head);
    printf("\n");
    printf("inserting 9\n");
    head = avl_insert(head, 9);
    print_preorder(head);
    printf("\n");
    printf("inserting 8\n");
    head = avl_insert(head, 8);
    print_preorder(head);
    printf("\n");
}
