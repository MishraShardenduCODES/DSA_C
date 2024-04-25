// 1.Write a C program to implement the stack using the
// singly linked list data structure.

#include <stdio.h>     // For standard input/output functions like printf, scanf
#include <stdlib.h>    // For functions involving memory allocation, process control functions
#include <string.h>    // For string manipulation functions like strcpy, strlen
#include <math.h>      // For mathematical functions like sqrt, sin, cos
#include <ctype.h>     // For functions to classify characters like isalpha, isdigit
#include <time.h>      // For functions to manipulate date and time
#include <stdbool.h>   // For boolean data type and true/false macros
#include <limits.h>    // For limits of integral types

struct node{
    int data;
    struct node*next;
};
struct node*head=0,*tail=0;

void peek(){
    if(head==0){
        printf("It's already empty \n");
    }else{
        printf("%d \n",tail->data);
    }
}

void display(){
    if(head==0){
        printf("It's empty \n");
    }else{
        struct node*temp=head;
        while(temp != tail){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf(" %d ",temp->data);
    }
}

void pop(){
    if(head==0){
        printf("It's already empty \n");
    }else{
        struct node*temp=head,*nextNode=head;
        nextNode=nextNode->next;
        while(temp->next!=tail){
            nextNode=nextNode->next;
            temp=temp->next;
        }
        tail=temp;
        free(nextNode);
    }
}

void push(){
    struct node*newNode,*temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Tell teh data : ");
    scanf("%d",&newNode->data);
    newNode->next=0;
    if(head==0 && tail==0){
        head=tail=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    }
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                peek();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}