#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a stack with given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        return NULL;
    }
    return stack;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expression) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, operand1, operand2;

    if (!stack) {
        return -1;
    }

    for (i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter the postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character from the input string
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
