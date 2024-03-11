#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf

struct node{
    struct node*prv;
    int data;
    struct node*next;
};
struct node*head;

void display(){
    struct node*temp;
    temp=head;
    while(temp!=0){
        pf("%d ",temp->data);
        temp=temp->next;
    }
}

void mke_dll(){
    int a;
    head=0; // Initialize head to 0 outside the loop
    do{
        pf("Press 0 to stop : ");
        sf("%d",&a);
        struct node*newNode,*temp;
        newNode=(struct node*)malloc(sizeof(struct node));
        pf("Tell the data : ");
        sf("%d",&newNode->data);
        newNode->prv=0;
        newNode->next=0;
        if(head==0){
            head=temp=newNode;
        }else{
            temp->next=newNode;
            newNode->prv=temp;
            temp=newNode;
        }
    }while(a!=0);
}

int main(){
    int a;
    while(1){
        pf("\n\n1.) Make a DLL \n2.) Stop \n3.) Display\nTell the option : ");
        sf("%d",&a);
        switch(a){
            case 1 : mke_dll()                  ; break;
            case 2 : pf("Program stopped!\n")   ; exit(EXIT_SUCCESS);
            case 3 : display();                 ; break;
        }
    }
    return 0;
}
