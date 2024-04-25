#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePrefix(char* prefix) {
    int length = strlen(prefix);
    
    for (int i = length - 1; i >= 0; i--) {
        if (isspace(prefix[i])) {
            continue; 
        }

        if (isdigit(prefix[i])) {
            int value = 0;
            int power = 1;
            
            while (i >= 0 && isdigit(prefix[i])) {
                value = (prefix[i] - '0') * power + value;
                power *= 10;
                i--;
            }
            i++;
            push(value);
        } else {
            int operand1 = pop();
            int operand2 = pop();
            int result;
            
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
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator '%c'\n", prefix[i]);
                    exit(1);
            }
            
            push(result);
        }
    }
    
    return pop();
}

int main() {
    char prefix[MAX_SIZE];
    
    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    
    size_t len = strlen(prefix);
    if (prefix[len - 1] == '\n') {
        prefix[len - 1] = '\0';
    }
    
    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);
    
    return 0;
}
