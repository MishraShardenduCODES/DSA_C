// 1.Write a C program to evaluate prefix expression
// provided by the user using stack data structure.
#include <stdio.h>
#include <ctype.h>
#define n 100

int stack[n],top = -1;

void push(int value) {
    if (top >= n-1){
        printf("Stack Overflow\n");
    }else{
        stack[++top] = value;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    }else{
        return stack[top--];
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluatePrefix(char prefix[]) {
    int i, operand1, operand2, result;
    for (i = 0; prefix[i] != '\0'; i++) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            operand2 = pop();
            operand1 = pop();
            switch (prefix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char prefix[n];
    printf("Enter the prefix expression: ");
    fgets(prefix, n, stdin);
    int result = evaluatePrefix(prefix);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    return 0;
}
