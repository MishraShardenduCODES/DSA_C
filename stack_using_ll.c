#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 

#define  pf printf
#define  sf scanf

struct node {
    int data;
    struct node *next;
}*head=NULL,*tail=NULL, *newNode=NULL, *temp=NULL;

void push() {
    newNode=(struct node *)malloc(sizeof(struct node));
    pf("Enter data: ");
    sf("%d", &newNode->data);
    newNode->next=NULL;
    if (head == NULL) {
        head=tail=newNode;
    } else {
        tail->next=newNode;
        tail=newNode;
    }
}

void pop() {
    if (head == NULL) {
        pf("Stack is empty\n");
    } else {
        if (head == tail) {
            free(head);
            head=tail=NULL;
        } else {
            temp=head;
            while (temp->next != tail) {
                temp=temp->next;
            }
            temp->next=NULL;
            free(tail);
            tail=temp;
        }
    }
}

void display() {
    if (head == NULL) {
        pf("Stack is empty\n");
    } else {
        temp=head;
        pf("Stack elements: ");
        while (temp != NULL) {
            pf("%d \n", temp->data);
            temp=temp->next;
        }
        pf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        pf("\nStack Operations\n");
        pf("1. Push\n");
        pf("2. Pop\n");
        pf("3. Display\n");
        pf("4. Exit\n");
        pf("Enter your choice: ");
        sf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                pf("Invalid choice\n");
        }
    }
    return 0;
}
