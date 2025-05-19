#include<stdio.h>
#include<ctype.h>

int stack[100];
int top = -1;

void push(char n) {
    stack[++top] = n;
}
char pop() {
    return stack[top--];
}

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char exp[]) {
    for(int i=0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if(isalnum(ch)) {
            printf("%c",ch);
        } else if(ch == '(') {
            push(ch);
        } else if(ch == ')') {
            while(top != -1 && stack[top] != '(') {
                printf("%c",pop());
            }
            pop();

        }
        else {
            while(top != -1 && precedence(stack[top]) > precedence(ch)) {
                printf("%c",pop());
            }
            push(ch);
        }
    }
    while(top != -1) {
        printf("%c", pop());
    }
}

int main() {
    char exp[100];
    printf("enter infix expression : ");
    scanf("%s",exp);
    printf("postfix : ");
    infixToPostfix(exp);
}

