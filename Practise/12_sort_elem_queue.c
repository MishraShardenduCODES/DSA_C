#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int q[MAX_SIZE];
int f = -1, r = -1;

inline int isEmpty() {
    return f == -1;
}

inline int isFull() {
    return (r == MAX_SIZE - 1);
}

void enq(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        f = r = 0;
    } else {
        r++;
    }
    q[r] = item;
}

int deq() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = q[f];
    if (f == r) {
        f = r = -1;
    } else {
        f++;
    }
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void sortQueue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot sort.\n");
        return;
    }
    for (int i = f; i <= r - 1; i++) {
        for (int j = f; j <= r + f - 1; j++) {
            if (q[j] > q[j + 1]) {
                int temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }
    printf("Queue sorted successfully.\n");
}

int main() {
    int choice, item;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Sort queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                if (scanf("%d", &item) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                enq(item);
                break;
            case 2:
                item = deq();
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                sortQueue();
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
