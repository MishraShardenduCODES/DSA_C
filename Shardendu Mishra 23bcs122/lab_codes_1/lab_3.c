#include <stdio.h>

#define STACK_SIZE 10

// Global variables
int stack[STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to compute sum, average, maximum, and minimum of numbers in the stack
void computeStatistics() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    int sum = 0, max = stack[top], min = stack[top];

    // Calculate sum, maximum, and minimum
    for (int i = top; i >= 0; i--) {
        sum += stack[i];
        if (stack[i] > max) {
            max = stack[i];
        }
        if (stack[i] < min) {
            min = stack[i];
        }
    }

    // Calculate average
    float average = (float)sum / (top + 1);

    // Push sum, average, max, and min onto the stack
    push(sum);
    push((int)average);
    push(max);
    push(min);
}

int main() {
    // Read 5 integer numbers into the stack
    printf("Enter 5 integer numbers:\n");
    for (int i = 0; i < 5; i++) {
        int num;
        scanf("%d", &num);
        push(num);
    }

    // Compute sum, average, max, and min
    computeStatistics();

    // Display the stack contents
    printf("Stack contents after computation:\n");
    while (top != -1) {
        printf("%d\n", pop());
    }

    return 0;
}
