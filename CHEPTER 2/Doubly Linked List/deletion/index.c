#include<stdio.h>
#include<stdlib.h>

// node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to traverse forward
void TraverseForward(struct Node* head){
    struct Node* p = head;
    while(p != NULL) {
        printf("Element : %d\n",p->data);
        if(p->next == NULL) break;
        p = p->next;
    }
    printf("\n");
}

// Function to traverse backward
void TraverseBackward(struct Node* tail) {
    struct Node* p = tail;
    while(p != NULL) {
        printf("Element : %d\n",p->data);
        p = p->prev;
    }
    printf("\n");
}

struct Node* DeleteAtIndex(struct Node* head,int index)
 {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if(index == 0) {
        struct Node* a = head;
        head = head->next;
        head->prev = NULL;
        free(a);
        return head;
    }

    struct Node* p =head;
    int i=0;
    while(i != index-1 && p != NULL) {
        p=p->next;
        i++;
    }

    if (p == NULL || p->next == NULL) {
        printf("Index out of bounds.\n");
        return head;
    }

    struct Node* q = p->next;
    p->next = q->next;
    
    if(q->next != NULL) {

        q->next->prev = p;
    }

    free(q);
    return head;
 }

int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->prev = NULL;
    head->next = n2;

    n2->data = 13;
    n2->prev = head;
    n2->next = n3;

    n3->data = 17;
    n3->prev = n2;
    n3->next = n4;

    n4->data = 23;
    n4->prev = n3;
    n4->next = NULL;

    head = DeleteAtIndex(head,2);

    printf("Traverse Forward\n");
    TraverseForward(head);    // Forward traversal

    struct Node* tail = head;     // find tail for backward traversal 
    while(tail->next != NULL) {
        tail = tail->next;
    }
    printf("traverse Backward\n");
    TraverseBackward(tail);    // backward traversal

    return 0;
}