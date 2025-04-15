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

struct Node* DeleteAtBiginning(struct Node* head) {
    
    struct Node* p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}

struct Node* DeleteAtEnd(struct Node* head) {
    struct Node* p = head;
    struct Node* q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    q->prev = p;
    p->next = NULL;
    free(q);
    return head;
    
} 
struct Node* DeleteAtIndex(struct Node* head,int index)
 {
    struct Node* p =head;
    struct Node* q = head->next;
    int i=0;
    while(i != index-1 && q->next != NULL) {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;

    free(q);
    return head;
 }
struct Node* DeleteAfterNode(struct Node* head,struct Node* prevNode) {
    struct Node* q = prevNode->next;

    prevNode->next = q->next;
    q->next->prev = prevNode;
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

    head = DeleteAtBiginning(head);

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