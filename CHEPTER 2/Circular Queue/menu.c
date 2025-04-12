// Menu-driven interface in main function for interactive input (used in real programs)

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
    int val, choice;
    
    printf("\nQueue menu\n");
    printf("1.enqueue\n 2.dequeue\n 3.peek\n 4.display\n 0.exit\n");
    while(1) {
        printf("enter choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter val for enqueue : ");
                scanf("%d",&val);
                Enqueue(val);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting..");
                return 0;
            default:
                printf("Invalid choice, try again..!");
        }
    }
}