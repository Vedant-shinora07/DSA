#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void printList(struct Node* head) {
    struct Node* ptr = head;
    while(ptr != NULL) {
        printf("Element : %d ",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtBig(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    ptr->prev = NULL;

    if(head != NULL) {
        head->prev = ptr;
    }
    head = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }
    struct Node* q = head;

    while(q->next != NULL) {
        q = q->next;
    }

    q->next = ptr;
    ptr->next = NULL;
    ptr->prev = q;
    return head;
}

struct Node* insertAfterValue(struct Node* head,struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    struct Node* p = prevNode->next;
    ptr->next = prevNode->next;
    ptr->prev = prevNode;

    if(prevNode->next != NULL) {
        p->prev = ptr;
    }
    prevNode->next = ptr;
    return head;
}

struct Node* deleteValue(struct Node* head, int val) {
    struct Node* ptr = head;

    if(head == NULL) return NULL;

    if(ptr->data == val) {
        head = head->next;
        free(ptr);
        return head;
    }   

    while(ptr->data != val && ptr->next != NULL) {
        ptr = ptr->next;
    }
    if(ptr == NULL) {
        printf("value not found");
    }
    if(ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    if(ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    return head;
    
}
int main() {
    struct Node* head = NULL;

    head = insertAtBig(head, 10);
    head = insertAtBig(head, 20);
    head = insertAtBig(head, 30);
    head = insertAfterValue(head,head->next,90);
    head = deleteValue(head, 90);
    printList(head);
}