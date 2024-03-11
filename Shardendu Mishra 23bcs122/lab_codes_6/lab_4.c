#include<stdio.h>
#include<stdlib.h>

#define pf printf
#define sf scanf

struct node {
    int val;
    int pow;
    struct node *next;
};

void insrt_end(struct node **head_ref, struct node **tail_ref) {
    struct node *head = *head_ref, *tail = *tail_ref, *newNode;
    while (1) {
        pf("If your equation has more variable, press 1. Else, press 2: ");
        int a;
        sf("%d", &a);
        if (a != 1) {
            break;
        }
        newNode = (struct node*)malloc(sizeof(struct node));
        pf("Tell the coefficient and the power of x: ");
        sf("%d %d", &newNode->val, &newNode->pow);
        if (head == NULL) {
            head = tail = newNode;
            head->next = NULL;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = NULL;
        }
    }
    *head_ref = head;
    *tail_ref = tail;
}

int main() {
    struct node *head1 = NULL, *tail1 = NULL;
    struct node *head2 = NULL, *tail2 = NULL;

    pf("Create Linked List 1: ");
    insrt_end(&head1, &tail1);

    pf("Create Linked List 2: ");
    insrt_end(&head2, &tail2);

    struct node *temp1 = head1, *temp2 = head2;
    pf("Result of adding the two equations: ");
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->pow == temp2->pow) {
            pf("+ (%d * (x^%d)) ", temp1->val + temp2->val, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->pow < temp2->pow) {
            pf("+ (%d * (x^%d)) ", temp1->val, temp1->pow);
            temp1 = temp1->next;
        } else {
            pf("+ (%d * (x^%d)) ", temp2->val, temp2->pow);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) {
        pf("+ (%d * (x^%d)) ", temp1->val, temp1->pow);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        pf("+ (%d * (x^%d)) ", temp2->val, temp2->pow);
        temp2 = temp2->next;
    }

    return 0;
}
