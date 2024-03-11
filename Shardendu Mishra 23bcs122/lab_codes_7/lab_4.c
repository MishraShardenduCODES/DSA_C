// 4.Write a C program to create a doubly linked list
// of integers and perform the following operations:
// ● Insert a node at the beginning
// ● Insert a node at the end
// ● Insert a node after a given position
// ● Delete a node at the beginning
// ● Delete a node at the end
// ● Delete a node at a given position
// ● Display the elements of the list in forward and
// reverse order.

#include <stdio.h>     // For standard input/output functions like printf, scanf
#include <stdlib.h>    // For functions involving memory allocation, process control functions
#include <string.h>    // For string manipulation functions like strcpy, strlen
#include <math.h>      // For mathematical functions like sqrt, sin, cos
#include <ctype.h>     // For functions to classify characters like isalpha, isdigit
#include <time.h>      // For functions to manipulate date and time
#include <stdbool.h>   // For boolean data type and true/false macros
#include <limits.h>    // For limits of integral types

struct node{
    struct node*prev;
    int data;
    struct node*next;
}*head=0,*tail=0,*newNode;

void make_lnkd_lst(){
    while(1){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("TEll : ");
        scanf("%d",&newNode->data);
        newNode->next=0;
        newNode->prev=0;
        if(head == 0 && tail == 0){
            head = tail = newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=tail->next;
        }
        printf("Press 1 to stop : ");
        int a;
        scanf("%d",&a);
        if (a==1) break;
    }
}

void insrt_bgn(){
    if(head == 0 && tail == 0){
        make_lnkd_lst();
        return;
    }else{
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->next=0;
        newNode->prev=0;
        printf("TEll : ");
        scanf("%d",&newNode->data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void insrt_end(){
    if(head == 0 && tail == 0){
        make_lnkd_lst();
        return;
    }else{
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("TEll : ");
        scanf("%d",&newNode->data);
        newNode->next=0;
        newNode->prev=0;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}


void insrt_posn() {
    if (head == NULL && tail == NULL) {
        make_lnkd_lst();
        return;
    } else {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("TEll : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        int posn;
        printf("Tell the position : ");
        scanf("%d", &posn);
        struct node* temp = head;
        int i = 1;
        while (temp != NULL && i < posn) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("This position is not available \n");
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}


void dlt_bgn(){
    struct node*temp=head;
    if(head == 0 && tail == 0){
        printf("It's empty \n");
    }else{
        head=head->next;
        head->prev=0;
        free(temp);
    }
}

void dlt_end(){
    if(head == 0 && tail == 0){
        printf("It's empty \n");
    }else{
        struct node*temp=tail;
        tail=tail->prev;
        tail->next=0;
        free(temp);
    }
}

void dlt_posn() {
    if (head == NULL) {
        printf("It's empty \n");
        return;
    }
    int posn;
    printf("Tell the position : ");
    scanf("%d", &posn);
    struct node* temp = head;
    int i = 1;
    while (temp != NULL && i < posn) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("This position is not available \n");
        return;
    }
    struct node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != NULL) {
        delNode->next->prev = temp;
    } else {
        tail = temp; // Update tail if the last node is deleted
    }
    free(delNode);
}

void display(){
    struct node*temp=head;
    if(head == 0){
        printf("It's empty \n");
    }else{
        while(temp->next != 0){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf(" %d ",temp->data);
    }
}

int main() {
    int choice;

    // Loop to display menu until the user chooses to exit
    do {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert a node at the beginning\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node after a given position\n");
        printf("4. Delete a node at the beginning\n");
        printf("5. Delete a node at the end\n");
        printf("6. Delete a node at a given position\n");
        printf("7. Display the elements of the list in forward order\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to perform operations based on user choice
        switch(choice) {
            case 1:
                insrt_bgn();
                break;
            case 2:
                insrt_end();
                break;
            case 3:
                insrt_posn();
                break;
            case 4:
                dlt_bgn();
                break;
            case 5:
                dlt_end();
                break;
            case 6:
                dlt_posn();
                break;
            case 7:
                printf("Elements of the list in forward order:\n");
                display();
                break;
            case 8:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }
    }while(choice != 9);
    return 0;
}