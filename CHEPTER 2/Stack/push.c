// Push (insert) elements in the stack..

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

void display() {
    if(top == -1) {
        printf("stack is empty..!");
        return;
    }
    printf("stack elements : ");
    for(int i= top; i>=0; i--) {
        printf("%d ", stack[i]);
   }
    printf("\n");
    }

int main() {
    push(10);
    push(20);
    display();
    return 0;
}
