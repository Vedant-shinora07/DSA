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

    second -> data = 99;
    second -> next = third;

    third -> data = 17;
    third -> next = fourth;

    fourth -> data = 23;
    fourth -> next = NULL;

    traversal(head);
    printf("After Sorting\n");
    head = sortList(head);  
    traversal(head);
}