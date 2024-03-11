// 3.Write a C program to implement the operations of a
// double ended queue using a doubly linked list.

#include <stdio.h>    // For input and output functions like printf() and scanf()
#include <stdlib.h>   // For general utility functions like memory allocation and conversion functions
#include <math.h>     // For mathematical functions like sin(), cos(), sqrt(), etc.
#include <string.h>   // For string manipulation functions like strcpy(), strcat(), strlen(), etc.
#include <ctype.h>    // For character handling functions like isalpha(), isdigit(), etc.
#include <time.h>     // For date and time functions like time(), localtime(), etc.
#include <limits.h>   // For constants representing the limits of various data types
#include <stdbool.h>  
#define pf printf
#define sf scanf

struct node{
    int data ;
    struct node *next;
    struct node *prev;
}*head=0,*tail=0,*temp,*temp2; 

void insrt_bgn(){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d",&newNode->data);
    newNode->prev=0;
    if(head==0){
        head=tail=newNode;
        head->next=0;
    }else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}

void insrt_end(){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d",&newNode->data);
    newNode->next=0;
    if(head==0){
        head=tail=newNode;
        tail->next=0;
    }else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

void dlt_bgn(){
    temp=head;
    if(head==0){
        pf("It's empty");
    }else{
        head=head->next;
        head->prev=0;
    }
    free(temp);
}

void dlt_end(){
    temp=temp2=head;
    if(head == 0 ){
        pf("Its already empty");
    }else{
        temp2=temp2->next;
        while(temp->next!=tail){
            temp=temp->next;
            temp2=temp2->next;
        }
        tail=temp;
        tail->next=0;
        free(temp2);
    }
}

void display(){
    temp=head;
    if(head == 0){
        pf("It's Empty\n");
        return ;
    }
    while(temp!=0){
        pf("%d ",temp->data);
        temp=temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Double Ended Queue Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insrt_bgn();
                break;
            case 2:
                insrt_end();
                break;
            case 3:
                dlt_bgn();
                break;
            case 4:
                dlt_end();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while(choice != 6);

    return 0;
}