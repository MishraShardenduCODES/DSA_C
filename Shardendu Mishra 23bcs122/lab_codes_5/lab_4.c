#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (start != NULL) {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

void sortAscending() {
    struct Node *current = head, *index = NULL;
    int temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void sortDescending() {
    struct Node *current = head, *index = NULL;
    int temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    insert(6);

    printf("Original List:\n");
    display(head);

    sortAscending();
    printf("\nSorted List in Ascending Order:\n");
    display(head);

    sortDescending();
    printf("\nSorted List in Descending Order:\n");
    display(head);

    return 0;
}
