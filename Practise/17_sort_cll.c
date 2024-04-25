#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    printf("List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void bubbleSortAscending() {
    if (head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    }
    Node* current;
    Node* nextNode;
    int temp;
    int sorted;
    do {
        sorted = 1;
        current = head;
        do {
            nextNode = current->next;
            if (nextNode != head && current->data > nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                sorted = 0;
            }
            current = nextNode;
        } while (current != head);
    } while (!sorted);
}

void bubbleSortDescending() {
    if (head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    }
    Node* current;
    Node* nextNode;
    int temp;
    int sorted;
    do {
        sorted = 1;
        current = head;
        do {
            nextNode = current->next;
            if (nextNode != head && current->data < nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                sorted = 0;
            }
            current = nextNode;
        } while (current != head);
    } while (!sorted);
}

int main() {
    int choice, data;

    do {
        printf("\n1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Sort in ascending order\n");
        printf("4. Sort in descending order\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to insert at end: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertEnd(data);
                break;
            case 2:
                display();
                break;
            case 3:
                bubbleSortAscending();
                printf("List sorted in ascending order.\n");
                break;
            case 4:
                bubbleSortDescending();
                printf("List sorted in descending order.\n");
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
