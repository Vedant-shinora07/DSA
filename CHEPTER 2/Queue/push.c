// Enqueue (insert) elements in the queue..

#include<stdio.h>
#define size 100

int queue[size];
int front = -1,rear = -1;

void Enqueue(int n) {
    if(rear == size -1) {
        printf("Queue is overflow..!");
    } else {
        if(front == -1) front = 0;
        queue[++rear] = n;
        printf("Enqueued %d\n",n);
    }
}
void display() {
    if(rear == size-1) {
        printf("queue is empty..!");
        return;
    }
    printf("queue elements : ");
    for(int i=front; i<=rear; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    display();
}
