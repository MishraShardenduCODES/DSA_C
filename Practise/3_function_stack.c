#include <stdio.h>
#include <limits.h>

#define Mx 10
int arr[Mx];
int top = -1;
int sum = 0;
int max = INT_MIN;
int min = INT_MAX;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == Mx - 1;
}

void push(int data) {
    if (isFull()) {
        printf("The stack is full.\n");
        return;
    }
    top += 1;
    arr[top] = data;
}

int pop() {
    if (isEmpty()) {
        printf("The stack is empty.\n");
        return -1;
    }
    int value = arr[top];
    top -= 1;
    return value;
}

void peek() {
    if (isEmpty()) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", arr[top]);
}

void mx() {
    max = INT_MIN;
    min = INT_MAX;
    sum = 0;
    
    for (int i = 0; i <= top; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }
    
    printf("Sum of elements: %d\n", sum);
    printf("Average of element: %d\n", sum/5);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Push element onto the stack\n");
    printf("2. Pop element from the stack\n");
    printf("3. Peek at the top element\n");
    printf("4. Calculate sum, max, and min of the stack\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, data;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &data);
                push(data);
                break;
                
            case 2:
                if (!isEmpty()) {
                    printf("Popped element: %d\n", pop());
                } else {
                    printf("The stack is empty.\n");
                }
                break;
                
            case 3:
                peek();
                break;
                
            case 4:
                if (isEmpty()) {
                    printf("The stack is empty.\n");
                } else {
                    mx();
                }
                break;
                
            case 5:
                printf("Exiting the program.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}