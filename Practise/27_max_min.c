// 2.Write a C program to find the maximum and minimum
// elements in a doubly linked list.

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
}*head=0,*tail=0,*temp;

int max=INT_MIN,min=INT_MAX;

void insrt_end(){
    struct node * newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    int a;
    pf("Tell the data : ");
    sf("%d",&a);
    newNode->data = a;
    if(a>max){
        max=a;
    }
    if(a<min){
        min=a;
    }
    if(head == 0){
        head=tail=newNode;
        head->next=0;
        head->prev=0;
    }else{
        newNode->next=0;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}

int main(){ 
    int a;
    do{
        pf("Press 1 to stop and Press 2 to add element : ");
        sf("%d",&a);
        switch(a){
            case 1 : break ;
            case 2 : insrt_end() ; break ;
        }
    }while(a!=1);
    pf("%d is the max in the list \n%d is the min in the list\n",max,min);
}