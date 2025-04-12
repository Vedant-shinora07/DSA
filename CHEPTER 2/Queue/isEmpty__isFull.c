// isEmpty() and isFull() functions use for checks

#include<stdio.h>
#define size 100

int queue[size];
int front = -1,rear = -1;

int isFull() {
    return rear == size - 1;
}
int isEmpty() {
    return front == -1 || front > rear;
}

void Enqueue(int n) {
    if(isFull()) {
        printf("Queue is overflow..!");
    } else {
        if(front == -1) front = 0;
        queue[++rear] = n;
        printf("Enqueued %d\n",n);
    }
}
void Dequeue() {
    if(isEmpty()) {
        printf("queue is empty..!");
    } else {
        printf("Dequeued %d\n", queue[front++]);
    }
}
void peek() {
    if(isEmpty()) {
        printf("queue is Empty..!");
    } else {
        printf("Queu top element is :%d\n ", queue[front]);
    }
}
void display() {
    if(isEmpty()) {
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
    Dequeue();
    Dequeue();
    peek();
}
