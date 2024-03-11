#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

void insertAtPosition(int value, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, position);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; ++i) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted from the beginning.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted from the end.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted from the end.\n");
}

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted from position %d.\n", position);
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    for (int i = 1; i < position && temp != NULL; ++i) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted from position %d.\n", position);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specified position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specified position\n");
        printf("7. Display the linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
