#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTransversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = 12;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insertAfterANode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    // Your code goes here
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;
    second->data = 42;
    second->next = third;
    third->data = 13;
    third->next = fourth;
    fourth->data = 24;
    fourth->next = fifth;
    fifth->data = 45;
    fifth->next = NULL;

    printf("Linked List Before Insertion - \n");
    linkedListTransversal(head);
    // head = insertAtFirst(head, 00);
    // head = insertAtIndex(head,56,1);
    // head = insertAtEnd(head,56);
    head = insertAfterANode(head, second, 45);
    printf("Linked List After Insertion - \n");
    linkedListTransversal(head);

    return 0;
}