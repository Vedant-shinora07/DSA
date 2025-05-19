#include<stdio.h>
#define size 100

int cqueue[size];
int front = -1, rear = -1;

int isFull() {
    return front == (rear + 1) % size;   
}

int isEmpty() {
    return front == -1;
}

void enqueue(int n) {
    if(isFull()) {
        printf("queue is overflow..!");
        return;
    if(isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    }
    cqueue[rear] = n;
    printf("enqueued %d",n);
}

void dequeue() {
    if(isEmpty()) {
        printf("queue is empty..!");
        return;
    }  
        printf("dequeued %d",cqueue[front]);
    
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if(isEmpty()) {
        printf("queue is empty..!");
        return;
    } 
    int i = front;
    printf("queue elements : ");
    while(1) {
        printf("%d ",cqueue[i]);
        if(i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}