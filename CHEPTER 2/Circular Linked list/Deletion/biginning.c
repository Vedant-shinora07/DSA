//  delete element at the biginning in the circular linked list

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
struct Node* DeleteFirst(struct Node* head) {
    if(head == NULL) return NULL;

    // If there's only one node
    if(head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head;

    while(p->next != head) {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    free(q);
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

    head = DeleteFirst(head);
    Traversal(head);
    
}