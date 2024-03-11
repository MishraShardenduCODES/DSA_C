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
};

int main(){
    int choice,count=0;
    struct node*temp,*head=0;
    while(1){
        pf("1.) Tell the element \n2.) Exit \nTell the option : ");
        sf("%d",&choice);
        if(choice==2){
            break;
        }
        // dynamically allocating new node //
        // newNode holds addrres //
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode == NULL) {
            pf("Memory allocation failed.\n");
            return 1; // Return a non-zero value to indicate an error
        }
        pf("Tell the elemnt : ");
        sf("%d",&newNode->data);
        // makes sure the last element is pointing to null //
        newNode->next=0;
        if(head==0){
            // temp makes sure that it points to the next address of the last element //
            head=temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    int a=120;
    newNode->data=a;
    newNode->next=head;
    head=newNode;

    temp=head;
    while(temp!=0){
        pf("%d ",temp->data);
        temp=temp->next;
    }
    pf("\n");
}
