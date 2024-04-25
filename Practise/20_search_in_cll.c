#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Function to insert a node at the beginning of the circular linked list
void insertBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

// Function to insert a node at the end of the circular linked list
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

// Function to display the contents of the circular linked list
void display() {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to search for an element at a specified position in the circular linked list
void searchByPosition(int pos) {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    Node* temp = head;
    int i = 1;
    while (i < pos) {
        temp = temp->next;
        i++;
        if (temp == head) {
            printf("Invalid position.\n");
            return;
        }
    }
    printf("Element at position %d is: %d\n", pos, temp->data);
}

// Function to search for an element by its value in the circular linked list
void searchByValue(int value) {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found in the circular linked list\n", value);
}

// Main function with a menu-driven interface
int main() {
    int choice, data, position, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Display list\n");
        printf("4. Search element at specified position\n");
        printf("5. Search element by its value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the beginning: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 2:
                printf("Enter element to insert at the end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the position to search: ");
                scanf("%d", &position);
                searchByPosition(position);
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchByValue(value);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
