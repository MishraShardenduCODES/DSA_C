#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff; // Coefficient of the term
    int power; // Power of the term
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(Node** head, Node** tail, int coeff, int power) {
    Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Function to insert terms in the linked list
void inputPolynomial(Node** head, Node** tail) {
    int more = 1;
    while (more == 1) {
        int coeff, power;
        printf("Enter coefficient and power (format: coefficient power): ");
        scanf("%d %d", &coeff, &power);
        insertEnd(head, tail, coeff, power);
        printf("Do you want to enter more terms? (1 for Yes, 0 for No): ");
        scanf("%d", &more);
    }
}

// Function to display the polynomial linked list
void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    Node* temp = head;
    int first_term = 1;
    while (temp != NULL) {
        if (temp->coeff > 0 && !first_term) {
            printf(" + ");
        } else if (temp->coeff < 0) {
            printf(" - ");
            temp->coeff *= -1;
        }
        printf("%d*x^%d", temp->coeff, temp->power);
        first_term = 0;
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials represented as linked lists
Node* addPolynomials(Node* head1, Node* head2) {
    Node* resultHead = NULL;
    Node* resultTail = NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->power == temp2->power) {
            int sumCoeff = temp1->coeff + temp2->coeff;
            if (sumCoeff != 0) {
                insertEnd(&resultHead, &resultTail, sumCoeff, temp1->power);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->power > temp2->power) {
            insertEnd(&resultHead, &resultTail, temp1->coeff, temp1->power);
            temp1 = temp1->next;
        } else {
            insertEnd(&resultHead, &resultTail, temp2->coeff, temp2->power);
            temp2 = temp2->next;
        }
    }

    // Add remaining terms from list1 or list2
    while (temp1 != NULL) {
        insertEnd(&resultHead, &resultTail, temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        insertEnd(&resultHead, &resultTail, temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }

    return resultHead;
}

// Main function
int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    Node* resultHead = NULL;

    printf("Enter the first polynomial:\n");
    inputPolynomial(&head1, &tail1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(&head2, &tail2);

    printf("\nFirst polynomial: ");
    displayPolynomial(head1);

    printf("\nSecond polynomial: ");
    displayPolynomial(head2);

    resultHead = addPolynomials(head1, head2);
    printf("\nResult of adding the two polynomials: ");
    displayPolynomial(resultHead);

    return 0;
}
