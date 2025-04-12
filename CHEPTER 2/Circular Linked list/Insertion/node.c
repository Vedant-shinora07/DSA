//  Insert element after the given node in the circular linked list

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
struct Node* insertAtNode(struct Node* head, struct Node* prevNode,int data) {

    if(prevNode == NULL) return NULL;

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    printf("After insert after given node \n");
    head = insertAtNode(head,second,66);
    Traversal(head);
}