#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void insertBeginning() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element: ");
    scanf("%d", &newNode->data);
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element: ");
    scanf("%d", &newNode->data);
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = NULL;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void searchPosition() {
    int pos;
    printf("Enter the position to search: ");
    scanf("%d", &pos);
    int i = 1;
    struct node* temp = head;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL && i == pos) {
        printf("The element at position %d is: %d\n", pos, temp->data);
    } else {
        printf("Invalid position or list is empty.\n");
    }
}

void searchKey() {
    int key, i = 1;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d is present at position %d.\n", temp->data, i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("Element not found in the list.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Display list\n");
        printf("4. Search by position\n");
        printf("5. Search by key\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeginning();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                display();
                break;
            case 4:
                searchPosition();
                break;
            case 5:
                searchKey();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
