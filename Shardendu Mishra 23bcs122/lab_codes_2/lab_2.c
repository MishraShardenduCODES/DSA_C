#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of an operator
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Discard the '('
        }
    }

    // Pop remaining operators from stack to postfix
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Add null terminator to the postfix expression
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character from the input string
    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
