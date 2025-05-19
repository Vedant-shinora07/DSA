#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;

    if(newNode == NULL) {
        printf("mmory allocation failed");
        return;
    }
    
    newNode->next = NULL;
    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear ->next = newNode;
        rear = newNode;
    }
    printf("ENQUEUED %d",n);
}

void dequeue() {
    if(isEmpty()) {
        printf("queue is empty..!");
        return;
    }
    struct Node* ptr = front;
    printf("Dequeued %d",ptr->data);
    front = front->next;

    if(front == NULL ) {
        rear = NULL;
    }
    free(ptr);
}

void display() {
    if(isEmpty()) {
        printf("queue is empty..!");
        return;
    }
    struct Node* ptr = front;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}




