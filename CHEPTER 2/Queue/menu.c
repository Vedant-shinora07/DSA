// Menu-driven interface in main function for interactive input (used in real programs)

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
        printf("Queue is overflow..!\n");
    } else {
        if(front == -1) front = 0;
        queue[++rear] = n;
        printf("Enqueued %d\n",n);
    }
}
void Dequeue() {
    if(isEmpty()) {
        printf("queue is empty..!\n");
    } else {
        printf("Dequeued %d\n", queue[front++]);
    }
}
void peek() {
    if(isEmpty()) {
        printf("queue is Empty..!\n");
    } else {
        printf("Queu top element is :%d\n ", queue[front]);
    }
}
void display() {
    if(isEmpty()) {
        printf("queue is empty..!\n");
        return;
    }
    printf("queue elements : ");
    for(int i=front; i<=rear; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() {
   int val,choice;

   printf("\nQueue Menu\n");
   printf("1.Enqueue\n 2.Dequeue\n 3.peek\n 4.display\n 0.exit\n");
   while(1) {
    printf("enter choice : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter element for enqueue : ");
            scanf("%d", &val);
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
            printf("Exiting..!");
            return 0;
        default:
            printf("Invalid choice, try again..!");
    }

   }
}
