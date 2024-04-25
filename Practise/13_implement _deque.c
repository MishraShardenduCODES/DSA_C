#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

void insertRear(int item) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}

void insertFront(int item) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = item;
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear) {
            printf("%d ", deque[i]);
            i++;
        }
    } else {
        while (i < MAX_SIZE) {
            printf("%d ", deque[i]);
            i++;
        }
        i = 0;
        while (i <= rear) {
            printf("%d ", deque[i]);
            i++;
        }
    }
    printf("\n");
}

int main() {
    int choice, item;

    do {
        printf("\n1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Delete from rear\n");
        printf("4. Delete from front\n");
        printf("5. Display deque\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to insert at rear: ");
                if (scanf("%d", &item) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertRear(item);
                break;
            case 2:
                printf("Enter element to insert at front: ");
                if (scanf("%d", &item) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertFront(item);
                break;
            case 3:
                deleteRear();
                printf("Element deleted from rear.\n");
                break;
            case 4:
                deleteFront();
                printf("Element deleted from front.\n");
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
