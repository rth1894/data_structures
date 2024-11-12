#include <stdio.h>
#include <ctype.h>
#include <string.h>

int top = -1;
char stack[30];

int icp(char ch);
int isp(char ch);
void in_post(char exp[30]);
int isEmpty();
int isFull();
void push(char elem);
char pop();
void post_in(char postExp[30]);

int main() {
    char expression[30];
    printf("Enter expression: ");
    scanf("%s", expression);
    in_post(expression);
    return 0;
}

int icp(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 4;
    if (ch == '(')
        return 5;
    return 0;
}

int isp(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

void in_post(char exp[30]) {
    int k = 0, i = 0;
    char postExp[30];
    char token = exp[i];
    while (token != '\0') {
        if (isalpha(token)) {
            postExp[k++] = token;
        }
        else if (token == '(') {
            push(token);
        }
        else if (token == ')') {
            while (!isEmpty() && ((token = pop()) != '(')) {
                postExp[k++] = token;
            }
        }
        else {
            while (!isEmpty() && isp(stack[top]) >= icp(token)) {
                postExp[k++] = pop();
            }
            push(token);
        }
        i++;
        token = exp[i];
    }
    while (!isEmpty()) {
        postExp[k++] = pop();
    }
    postExp[k] = '\0';
    printf("Postfix expression: %s\n", postExp);

    // Convert postfix expression to infix
    post_in(postExp);
}

int isEmpty() {
    return (top < 0);
}

int isFull() {
    return (top == 29);
}

void push(char elem) {
    if (!isFull())
        stack[++top] = elem;
    else
        printf("Stack is Full!\n");
}

char pop() {
    if (!isEmpty())
        return stack[top--];
    else {
        printf("Stack is Empty\n");
        return '\0';
    }
}

void post_in(char postExp[30]) {
    char s1[30][30]; // Stack of strings for infix expressions
    int top = -1; // Local stack pointer for infix expressions

    for (int i = 0; postExp[i] != '\0'; i++) {
        char s1_elem[2] = {postExp[i], '\0'};
        
        if (isalpha(postExp[i])) {
            strcpy(s1[++top], s1_elem);
        } else {
            char op1[30], op2[30];
            strcpy(op1, s1[top--]);
            strcpy(op2, s1[top--]);
            char infix[30] = "(";
            strcat(infix, op2);
            strncat(infix, &postExp[i], 1);
            strcat(infix, op1);
            strcat(infix, ")");
            strcpy(s1[++top], infix);
        }
    }

    printf("Infix expression: %s\n", s1[top]);
}

