//  Delete element after the Node in the circular linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node* head) {
    struct Node* ptr = head;

    do {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}
struct Node* DeleteAtNode(struct Node* head, struct Node* prevNode) {
    if(head == NULL || prevNode == NULL || prevNode->next == NULL) return head;

    struct Node* ptr = prevNode->next;

     // If we're deleting the head node
    if(ptr == head) {
        head = head->next;
    }

    // If list has only one node and it's being deleted
    if(ptr == prevNode && ptr == head) {
        free(ptr);
        return NULL;
    }

    prevNode->next = ptr->next;
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

    head = DeleteAtNode(head,second);
    Traversal(head);
    
}