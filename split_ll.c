#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

int count = 0;

void makell() {
    while (1) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head1 == NULL) {
            head1 = tail2 = newnode;
            count++;
        } else {
            tail2->next = newnode;
            tail2 = newnode;
            count++;
        }
        int num;
        printf("Press 0 to stop: ");
        scanf("%d", &num);
        if (num == 0) {
            return;
        }
    }
}

void hlf() {
    struct node *temp = head1;
    for (int i = 0; i < count / 2 - 1; i++) {
        temp = temp->next;
    }
    tail1 = temp;
    temp = temp->next;
    head2 = temp;
    tail1->next = NULL;
}

void display() {
    struct node *temp = head1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = head2;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Split linked list into two halves\n");
        printf("3. Display linked lists\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                makell();
                break;
            case 2:
                hlf();
                printf("Linked list split into two halves.\n");
                break;
            case 3:
                printf("Linked List 1: ");
                display();
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
