#include<stdio.h>
#include<stdlib.h>

// node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void TraverseForward(struct Node* head) {
    struct Node* p = head;
    while(p != NULL) {
        printf("Element : %d\n",p->data);
        if(p == NULL) break;
        p = p->next;
    }
}

void Traversebackward(struct Node* tail) {
    struct Node* p = tail;
    while(p != NULL) {
        printf("Element : %d\n",p->data);
        p = p->prev;
    }
}

struct Node* InsertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;

    ptr->next = head;
    if(head != NULL) {
        head->prev = ptr;
    }
    return ptr;

}

struct Node* InsertatEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;

    struct Node* p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}

struct Node* InsertAtIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if(index == 0) {
        
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        return ptr;
    }
    struct Node* p = head;
    int i = 0;
    while(i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if(p == NULL) {
        printf("Index out of bounds..");
        free(ptr);
        return head;
    }
    ptr->next = p->next;
    ptr->prev = p;
    if(p->next != NULL) {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return head;
}

struct Node* InsertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = prevNode->next;

    ptr->next = prevNode->next;
    ptr->prev = prevNode;

    if(prevNode->next != NULL) {
        prevNode->next->prev = ptr;
    }
    prevNode->next = ptr;
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

    head = InsertAfterNode(head, head, 66);

    printf("Traverse Forward\n");
    
    // Forward traversal
    TraverseForward(head);

    // find tail for backward traversal 
    struct Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    printf("traverse Backward\n");

    // backward traversal
    Traversebackward(tail);

    return 0;
}