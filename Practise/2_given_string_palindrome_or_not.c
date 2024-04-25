#include <stdio.h>

#define Mx 5
int arr[Mx];
int top = -1;

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

int check_palindrome() {
    int temp[Mx];
    int tempTop = -1;
    for (int i = 0; i <= top; i++) {
        temp[++tempTop] = arr[top - i];
    }
    for (int i = 0; i <= top; i++) {
        if (arr[i] != temp[i]) {
            return 0;
        }
    }
    return 1;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Push element onto the stack\n");
    printf("2. Pop element from the stack\n");
    printf("3. Peek at the top element\n");
    printf("4. Check if the stack is full\n");
    printf("5. Check if the stack is empty\n");
    printf("6. Check if the stack is a palindrome\n");
    printf("7. Exit\n");
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
                if (isFull()) {
                    printf("The stack is full.\n");
                } else {
                    printf("The stack is not full.\n");
                }
                break;
                
            case 5:
                if (isEmpty()) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
                
            case 6:
                if (check_palindrome()) {
                    printf("The stack is a palindrome.\n");
                } else {
                    printf("The stack is not a palindrome.\n");
                }
                break;
                
            case 7:
                printf("Exiting the program.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}