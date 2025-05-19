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

void Enqueue(int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;

    if(newNode == NULL) {
        printf("Memory allocation failed..!");
        return;
    }
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d", n);
}

void Dequeue() {
    if(isEmpty()) {
        printf("queue is empty..!");
        return;
    }
    struct Node* ptr = front;
    printf("dequeued %d", ptr->data);
    front = front->next;

    if(front == NULL) {
        rear = NULL;
    }
    free(ptr);
}

void display() {
    if(isEmpty()) {
        printf("stack is empty..!");
        return;
    }
    printf("Queue elements : ");
    struct Node* ptr = front;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }    
    printf("\n");
}

int main() {
    int val,choice;

   printf("\nQueue Menu\n");
   printf("1.Enqueue\n 2.Dequeue\n 3.display\n 0.exit\n");
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