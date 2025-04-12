
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *ptr = head;

    do
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *DeleteAtBeginning(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head == head->next)
    {
        free(head);
        return NULL;
    }
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    return head;
}

struct Node *DeleteAtIndex(struct Node *head, int index)
{
    if (head == NULL)
        return NULL;

    if (head == head->next)
    {
        free(head);
        return NULL;
    }
    if (index == 0)
    {
        struct Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
        return head;
    }
    struct Node *a = head;
    struct Node *b = head->next;
    int i = 0;
    while (i != index - 1 && a->next != head)
    {
        a = a->next;
        b = b->next;
        i++;
    }
    a->next = b->next;
    free(b);
    return head;
}

struct Node *DeleteAtEnd(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head == head->next)
    {
        free(head);
        return NULL;
    }

    struct Node *a = head;
    struct Node *b = head->next;

    while (a->next->next != head)
    {
        a = a->next;
        b = b->next;
    }
    a->next = b->next;
    free(b);
    return head;
}

struct Node *DeleteAfterNode(struct Node *head, struct Node *prevNode)
{
    if (head == NULL || prevNode == NULL)
        return head;

    struct Node *ptr = prevNode->next;

    if (ptr == head)
    {
        head = head->next;
    }
    if (ptr == prevNode && ptr == head)
    {
        free(ptr);
        return NULL;
    }
    prevNode->next = ptr->next;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 17;
    third->next = fourth;

    fourth->data = 23;
    fourth->next = head;

    head = DeleteAfterNode(head, second);
    Traversal(head);
}