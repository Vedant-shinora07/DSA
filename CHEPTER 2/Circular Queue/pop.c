// Dequeue (delete) the elements from the circular queue..

#include<stdio.h>
#define size 5

int cqueue[size];
int front = -1, rear = -1;

void Enqueue(int n) {
    if(front == (rear + 1) % size) {
        printf("queue is overflow..!\n");
        return;
    }
    if(front == -1) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    cqueue[rear] = n;
    printf("Enqueued %d\n", n);
}
void dequeue() {
    if(front == -1) {
        printf("queue is empty..!");
    } else {
        printf("Dequeued %d\n",cqueue[front]);
    }
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if(front == -1) {
        printf("Queue is empty..!\n");
        return;
    }
    printf("circular queue elements : ");
    int i = front;
    while(1) {
        printf("%d ",cqueue[i]);
        if(i == rear) break;
        i = (i+1) % size;
    }
    printf("\n");
}
int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    display();
    Enqueue(60);
    dequeue();
    dequeue();
    Enqueue(30);
    display();
    
}