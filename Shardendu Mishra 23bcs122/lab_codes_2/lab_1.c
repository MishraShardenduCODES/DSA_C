#include <stdio.h>
#include <stdlib.h>

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

// Function to read an expression and print the precedence of operators
void printOperatorPrecedence() {
    char expr[MAX_SIZE];
    printf("Enter the expression: ");
    fgets(expr, sizeof(expr), stdin);

    printf("Operator Precedence:\n");
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isOperator(expr[i])) {
            printf("%c : %d\n", expr[i], precedence(expr[i]));
        }
    }
}

int main() {
    printOperatorPrecedence();
    return 0;
}
