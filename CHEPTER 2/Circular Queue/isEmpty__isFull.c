// isEmpty() and isFull() functions use for checks

#include<stdio.h>
#define size 5

int cqueue[size];
int rear = -1, front = -1;

int isFull() {
    return (front == (rear + 1) % size);
}
int isEmpty() {
    return front == -1;
}

void Enqueue(int n) {
    if(isFull()) {
        printf("Queue is overflow..!\n");
        return;
    }
    if(isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    cqueue[rear] = n;
    printf("Enqueued %d\n",n);
}
void Dequeue() {
    if(isEmpty()) {
        printf("Queue is empty..!\n");
    } else {
        printf("Dequeued %d\n",cqueue[front]);
    }
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}
void peek() {
    if(isEmpty()) {
        printf("Queue is empty..!\n");
    } else {
        printf("queue top element : %d\n ",cqueue[front]);
    }
}

void display() {
    if(front == -1) {
        printf("Queue is empty..!\n");
        return;
    }
    int i = front;
    printf("circular queue elements : ");
    while(1) {

        printf("%d ",cqueue[i]);
        if(i == rear) break;
        i = (i + 1) % size;
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
    Dequeue();
    Dequeue();
    display();
    peek();

}