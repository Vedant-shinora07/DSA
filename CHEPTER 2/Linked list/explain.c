// Explaination and exicution in linked list
// Linked list Traverdal

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void linkedListTraversal(struct Node *ptr) {
   while(ptr != NULL) {
    printf("Element : %d\n",ptr -> data);
    ptr = ptr -> next;
   }
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;

    // Allocate memory for Nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second Nodes
    head -> data = 7;
    head -> next = second;

    // Link second and third Nodes
    second -> data = 13;
    second -> next = third;

    // terminate the list at the third Node
    third -> data = 16;
    third -> next = NULL;

    // call the function..
    linkedListTraversal(head);
}