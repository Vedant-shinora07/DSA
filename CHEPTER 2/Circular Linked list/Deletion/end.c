//  delete element at the end in the circular linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node* head) {
    struct Node* ptr = head;

    do {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}
struct Node* DeleteAtEnd(struct Node* head) {
    if(head == NULL) return NULL;

    if(head == head->next) {
        free(head);
        return NULL;
    }

    struct Node* a = head;
    struct Node* b = head->next;

    while(b->next != head) {
        a = a->next;
        b = b->next;
    }
    a->next = b->next;
    free(b);
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
    fourth -> next = head;

    head = DeleteAtEnd(head);
    Traversal(head);
    
}