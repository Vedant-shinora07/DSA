// Menu-driven interface in main function for interactive input (used in real programs)

#include<stdio.h>
#define size 30


int stack[size];
int top = -1; // stack is empty 

// check if stack is empty
int isEmpty() {
    return top == -1;
}

// check if stack is full
int isFull() {
    return top == size -1;
}

void push(int n) {
    if(isFull()) {
        printf("stack is overflow..!\n");
        return;
    }
    
        stack[++top] = n;
        printf("pushed %d\n",n);
    }


void pop() {
    if(isEmpty()) {
        printf("Stack is empty..!\n");
        return;
    } 
        printf("popped %d\n", stack[top--]);
    }


void peek() {
    if(isEmpty()) {
        printf("stack is empty..!\n");
        return;
    }
        printf("Top element of the stack is : %d\n",stack[top]);
    }


void display() {
    if(isEmpty()) {
        printf("stack is empty..!\n");
        return;
    }
    printf("stack elements : ");
    for(int i=top; i>=0; i--) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main() {
   int choice,n;
   
   printf("\nstack menu\n");
   printf("1.push\n 2.pop\n 3.peek\n 4.Display\n 5.check isEmpty\n 6.check isFull\n 0.Exit\n");
   while(1) {
        printf("Enter your choice..");
        scanf("%d",&choice);
        
        switch (choice)
   {
       case 1: 
       printf("Enter element to push :");
       scanf("%d",&n);
       push(n);
       break;
       case 2:
       pop();
       break;
       case 3:
       peek();
       break;
       case 4:
       display();
       break;
       case 5:
       isEmpty();
       break;
       case 6:
       isFull();
       break;
       case 0:
       printf("Exiting..!");
       return 0;
       default:
       printf("Invalid choice, try again!\n");
       
    }
}
}

