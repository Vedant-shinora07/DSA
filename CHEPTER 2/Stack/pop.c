// pop (delete) the elements from the stack..

#include<stdio.h>
#define size 100

int stack[size];
int top = -1;

void push(int n) {
    if(top == size -1) {
        printf("stack is overflow..!");
    } else {
        stack[++top] = n;
        printf("pushed %d\n",n);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack is empty..!");
    } else {
        int pop = stack[top--];
        printf("popped %d\n", pop);
    }
}

void display() {
    if(top == -1) {
        printf("stack is empty..!");
        return;
    }
    printf("stack elements : ");
    for(int i=top; i>=0; i--) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(30);
    push(40);
    display();
    pop();
    pop();
    display();
}