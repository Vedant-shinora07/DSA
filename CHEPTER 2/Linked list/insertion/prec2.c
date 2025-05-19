#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node* head) {
    struct Node* ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    head = ptr;

    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 40);
    head = insertAfterNode(head, head->next, 15);
    Traversal(head);
}