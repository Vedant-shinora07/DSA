//  Insert element at the biginning in the circular linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node* head) {

    if(head == NULL) return;
    struct Node* ptr = head;
    do {
        printf("Element is %d\n",ptr ->data);
        ptr = ptr ->next;
    } while(ptr != head);
}
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;

    if(head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    struct Node* p = head;
    while(p->next != head) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr; 
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

    Traversal(head);
    printf("After insert At first \n");
    head = insertAtFirst(head,66);
    Traversal(head);
}