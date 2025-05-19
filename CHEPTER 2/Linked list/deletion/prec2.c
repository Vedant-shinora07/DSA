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

struct Node* insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if(head == NULL) return NULL;

    struct Node* p = head;
    head = head->next;
    free(p);
    return head;
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

struct Node* deleteAtEnd(struct Node* head) {
    if(head == NULL) return NULL;

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node* deleteValue(struct Node* head, int value) {
    if(head == NULL) return NULL;

    struct Node* p = head;
    struct Node* q = head->next;

    struct Node* a = head;
    if(head->data == value) {
        head = head->next;
        free(a);
        return head;
    }

    while(q->data != value && q->next != NULL) {
        p = p ->next;
        q = q->next;
    }
    if(q->data == value) {
        p->next = q->next;
        free(q);
    } else {
        printf("element not found..!");
        return 0;
    }
    return head;
}

struct Node* searchNode(struct Node* head, int value) {
    struct Node* ptr = head;
    while(ptr != NULL) {
        if(ptr->data == value) return ptr;
        ptr = ptr->next;
    }
}

struct Node* sortList(struct Node* head) {
    if(head == NULL || head->next == NULL) return head;

    struct Node* i;
    struct Node* j;
    int temp;

    for(i = head; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
            temp = i->data;
            i->data = j->data;
            j->data = temp;
            }
        }
    }
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtFirst(head,10);
    head = insertAtEnd(head,30);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,50);
    head = insertAtEnd(head,40);
    traversal(head);
    printf("Sort");
    head = sortList(head);
    traversal(head);
}