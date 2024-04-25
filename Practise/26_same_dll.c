#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head1 = NULL;
struct node *tail1 = NULL;
struct node *head2 = NULL;
struct node *tail2 = NULL;

int cnt1 = 0;
int cnt2 = 0;

void insert_end(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
        newNode->prev = NULL;
    } else {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void display(struct node *start) {
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

int main() {
    printf("Please input the first linked list:\n");
    int choice = 1;
    while (choice != 3) {
        printf("Press 1 to assign elements in the first linked list, 2 to assign in the second linked list, and 3 to stop: ");
        scanf("%d", &choice);
        int data;
        switch (choice) {
            case 1:
                printf("Enter data for the first linked list: ");
                scanf("%d", &data);
                insert_end(&head1, &tail1, data);
                cnt1++;
                break;
            case 2:
                printf("Enter data for the second linked list: ");
                scanf("%d", &data);
                insert_end(&head2, &tail2, data);
                cnt2++;
                break;
        }
    }

    int stop = 0;
    if (cnt1 != cnt2) {
        stop = 1;
    } else {
        struct node *temp1 = head1;
        struct node *temp2 = head2;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data != temp2->data) {
                stop = 1;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    
    if (stop) {
        printf("The two doubly linked lists are not equivalent.\n");
    } else {
        printf("The two doubly linked lists are equivalent.\n");
    }

    return 0;
}
