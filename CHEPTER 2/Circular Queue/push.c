// Enqueue (insert) elements in the circular queue..

#include<stdio.h>
#define size 5

int cqueue[size];
int front = -1, rear = -1;

void enqueue(int n) {
    if(front == (rear + 1) % size) {
        printf("Queue is overflow..!");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear+1) % size;
    }
    cqueue[rear] = n;
    printf("enqueued %d\n",n);
}

void display() {
    if(front == -1) {
        printf("Queue is empty..!");
        return;
    }
    printf("circular queue elements :");
    int i = front;
    while(1) {
        printf("%d ",cqueue[i]);
        if(i == rear) break;
        i = (i+1) % size;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    display();
}