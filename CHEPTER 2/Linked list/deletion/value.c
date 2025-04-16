// Deletion of element with a given value from the linked list

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

struct Node* deleteAtValue(struct Node* head,int value) {
    struct Node* p = head;
    struct Node* q = head->next;

    struct Node* a= head;
    if(head->data == value) {
        head = head->next;
        free(a);
        return head;
    }
    while(q->data != value && q->next !=NULL) {
        p = p->next;
        q = q->next;
    }
    if(q->data == value) {

        p->next = q->next;
        free(q);
    } else {
        printf("value not found..!");
        return 0;
    }
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
    printf("After delete an element with given value \n");
    head = deleteAtValue(head,7);  
    traversal(head);
}