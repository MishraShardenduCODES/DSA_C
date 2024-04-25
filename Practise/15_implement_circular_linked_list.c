#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

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

void insertEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertBeginning(data);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* current = head;
    int count = 1;
    while (count < position - 1 && current->next != head) {
        current = current->next;
        count++;
    }

    if (count != position - 1) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;

    if (current == tail) {
        tail = newNode;
    }
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }

    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        head = tail = NULL;
    } else {
        prev->next = head;
        tail = prev;
    }

    free(current);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    int count = 1;

    while (count < position && current->next != head) {
        prev = current;
        current = current->next;
        count++;
    }

    if (count != position) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = current->next;

    if (current == tail) {
        tail = prev;
    }

    free(current);
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

int main() {
    int choice, data, position;

    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertBeginning(data);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertEnd(data);
                break;
            case 3:
                printf("Enter element to insert: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                printf("Enter position to insert: ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertAtPosition(data, position);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                deleteAtPosition(position);
                break;
            case 7:
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
