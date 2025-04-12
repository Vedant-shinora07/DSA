// Deletion after given index in the Linked list

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

struct Node* deleteIndex(struct Node* head,int index) {
    struct Node* p = head;
    struct Node* q = head ->next;

    for(int i=0; i != index - 1; i++) {
        p = p->next;
        q = q->next;
    }
    p ->next = q ->next;
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
    fourth -> next = NULL;

    traversal(head);
    printf("After delete an element from give index\n");
    head = deleteIndex(head,2);  
    traversal(head);
}