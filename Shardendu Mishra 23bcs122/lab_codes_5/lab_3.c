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
    struct Node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAscending() {
    struct Node *temp1, *temp2;
    for (temp1 = head; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->data > temp2->data) {
                swap(&(temp1->data), &(temp2->data));
            }
        }
    }
}

void bubbleSortDescending() {
    struct Node *temp1, *temp2;
    for (temp1 = head; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->data < temp2->data) {
                swap(&(temp1->data), &(temp2->data));
            }
        }
    }
}

int main() {
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        insert(value);
    }

    printf("Original linked list:\n");
    display(head);

    bubbleSortAscending();
    printf("Sorted linked list (ascending order):\n");
    display(head);

    bubbleSortDescending();
    printf("Sorted linked list (descending order):\n");
    display(head);

    return 0;
}
