#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory allocation failed..");
        return;
    }
    newNode->data = n;
    newNode->next = top;
    top = newNode;
    printf("pushed %d",n);
}

void pop() {
    if(isEmpty()) {
        printf("stack is empty..!");
        return;
    }
    struct Node* ptr = top;
    printf("popped %d", ptr->data);
    top = top->next;
    free(ptr);
}

void display() {
    if(isEmpty()) {
        printf("Stack is empty..!");
        return;
    }
    printf("stack elements : ");
    struct Node* ptr = top;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice, val;

    printf("\nstack menu\n");
    printf("1.push\n 2.pop\n 3.display\n 0.Exit\n");
    while(1) {
         printf("Enter your choice..");
         scanf("%d",&choice);
         
         switch (choice)
    {
        case 1: 
        printf("Enter element to push :");
        scanf("%d",&val);
        push(val);
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 0:
        printf("Exiting..!");
        return 0;
        default:
        printf("Invalid choice, try again!\n");
        
     }
 }
 }