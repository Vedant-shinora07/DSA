
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node *head) {
    if(head == NULL) return;

    struct Node* ptr = head;
    do {
        printf("ELement : %d\n",ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}

struct Node* InsertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if(head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    struct Node* p = head;
    while(p->next != head) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}

struct Node* insertAtIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if(head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    if(index == 0) {
        struct Node *temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        head = ptr;
        return head;
    }

    struct Node* p = head;
    int i=0;
    while(i != index - 1 && p->next != head) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node *ptr =(struct Node*)
    malloc(sizeof(struct Node));
    ptr->data = data;
    
    if(head == NULL) {
        ptr->next = ptr;
        return ptr;
    }
    struct Node* p = head;
    while(p->next != head) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    
    if(prevNode == NULL) return head;

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

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
    fourth -> next = head;

    head = insertAfterNode(head,second,66);
    Traversal(head);
}