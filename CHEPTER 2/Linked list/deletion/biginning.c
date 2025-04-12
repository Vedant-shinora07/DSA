// Deletion at the first in the Linked list

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

struct Node* deleteFirst(struct Node* head) {
    struct Node* ptr = head;
    head = head ->next;
    free(ptr);
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
    printf("After delete an element at the first position\n");
    head = deleteFirst(head);  
    traversal(head);
}