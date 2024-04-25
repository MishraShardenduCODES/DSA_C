#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        return 0;
    }
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    
    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {
            i++;
            continue; 
        }
        
        if (isdigit(postfix[i])) {
            int value = postfix[i] - '0'; // Convert single character digit to integer
            push(value);
        } else {
            int operand2 = pop();
            int operand1 = pop();
            int result;
            
            switch (postfix[i]) {
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
                    printf("Error: Invalid operator '%c'\n", postfix[i]);
                    exit(1);
            }
            push(result);
        }
        i++;
    }
    
    return pop();
}


int main() {
    char postfix[MAX_SIZE];
    
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    
    int len = strlen(postfix);
    if (postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }
    
    int ans = evaluatePostfix(postfix);
    printf("ans: %d\n", ans);
    
    return 0;
}
