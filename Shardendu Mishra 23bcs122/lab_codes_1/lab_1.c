#include <stdio.h>
#include <stdlib.h>

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

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; --i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack(MAX_SIZE);
    int choice, item;

    if (!stack) {
        printf("Memory allocation failed\n");
        return -1;
    }

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(stack, item);
                break;
            case 2:
                item = pop(stack);
                if (item != -1) {
                    printf("Popped element: %d\n", item);
                }
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
