// Insertion at the end in the Linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traversal(struct Node *ptr) {
    while(ptr != NULL) {
    printf("Elements %d\n", ptr ->data);
    ptr = ptr ->next;
    }    
}

struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;    
    struct Node* p = head;

    while(p->next != NULL) {
        p = p ->next;
    }
    p ->next = ptr;
    ptr ->next = NULL;
    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;

    second -> data = 13;
    second -> next = third;

    third -> data = 17;
    third -> next = fourth;

    fourth -> data = 23;
    fourth -> next = NULL;

    traversal(head);
    printf("After insert an element at the last position\n");
    head = insertAtEnd(head, 56);
    traversal(head);
}