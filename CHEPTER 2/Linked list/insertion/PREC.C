// Insertion at the first in the Linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node *ptr) {
    while(ptr != NULL) {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node* insertAtEnd(struct Node* head,int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    
    if(head == NULL) return NULL;
    struct Node* p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    if(head == NULL) return NULL;

    if(index == 0) {
        struct Node* a = head;
        while(a->next != NULL) {
            a = a->next;
        }
        ptr->next = a->next;
        a->next = ptr;
        return head;
    }
    
    struct Node* p = head;
    int i=0;
    while(i != index-1 && p->next != NULL) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node* insertAtNode(struct Node* head, struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    if(head == NULL) return NULL;

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
    fourth -> next = NULL;

    head = insertAtNode(head,second,66);
    Traversal(head);
    
}