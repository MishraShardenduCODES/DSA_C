// 3.Write a C program to sort the elements of a Queue
// data structure.
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define pf printf
#define sf scanf
#include<math.h>
#define n 10

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

void insertRear(int item) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}

void insertFront(int item) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = item;
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    int i = front;
    printf("Deque: ");
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
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 2:
                printf("Enter element to insert at front: ");
                scanf("%d", &item);
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
