#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to peek at the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack[top];
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("Popped value: %d\n", pop());
                break;
            case 3:
                printf("Top value: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
