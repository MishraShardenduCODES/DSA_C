// THIS PROGRAMS CONTAINS ALL TEH FUNCTION OF LINKED LIST AND ITS IMPLEMENTATION IT HAS TO BE FURTHER MODIFIED FOR A FEW FUNCTIONS //
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf

int count=0;
struct node{
    int data ;
    struct node*next;
};
struct node*head=0;

void display(){
    count=0;
    struct node*temp=head;
    pf("\nThe linked list is given by : ");
    while(temp != 0){
        pf("%d ",temp->data);
        temp=temp->next;
    }
    pf("\n");
}

void dlt_bgn(){
    struct node*temp;
    if(head==0){
        pf("Already Empty");
    }else{
        temp=head;
        head=head->next;
        free(temp);
    }
}

void dlt_posn(){
    struct node*temp,*nextNode;
    int posn,i=0;
    pf("Tell the posn from which u wanna delete : ");
    sf("%d",&posn);
    if(posn>count){
        pf("Invalid \n");
        return;
    }else{
        temp=head;
        while(i<posn-1){
            temp=temp->next;
            i++;
        }
        nextNode=temp->next;
        temp->next=nextNode->next;
        free(nextNode);
        count--;
    }
}

void dlt_end(){
    struct node*temp,*prvNode;
    temp=head;
    while(temp->next!=0){
        prvNode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }else{
        prvNode->next=0;
    }
    free(temp);
}

void add_start(){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the new element : ");
    sf("%d",&newNode->data);
    newNode->next=head; // Update the next pointer of the new node
    head=newNode; // Set the head to the new node
    count++;
}

void add_posn(){
    int i=0,posn,num;
    struct node*temp=head;
    int count=0;
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    free(temp);
    pf("Tell the number and at what position we have to add : ");
    sf("%d%d",&num,&posn);
    if(posn>count){
        pf("This position is not available \n");
        return;
    }else{
        struct node*temp,*newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        temp=head;
        while(i<posn){
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        newNode->data=num;
        temp->next=newNode;
    // }

}

void mke_ll(){
    struct node*temp,*newNode;
    int choice;
    head=0;
    // count =0;   
    while(1){
        int num;
        pf("Press 1 to stop else to continue : ");
        sf("%d",&num);
        if(num==1){
            break;
        }
        // Allocate memory for newNode within the loop
        newNode=(struct node*)malloc(sizeof(struct node));
        pf("Tell the data : ");
        sf("%d",&newNode->data);
        newNode->next=0;
        if(head==0){
            temp=head=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
        count++;
    }
    temp=head;                    
}

void add_end(){ 
    struct node*temp=head,*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the element : ");
    sf("%d",&newNode->data);
    newNode->next=0;
    if(head==0){
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newNode;
    count++;
}

int main(){
    while(1){
        int choice;
        pf("1.) Make a ll \n2.) Add element at the start of ll \n3.) Add element at the end of ll \n4.) Add element at the any position of ll \n5.) Delete element at the start of ll \n6.) Delete element at the end of ll \n7.) Delete element at the any position of ll \n8.) Display \n9.)Exit \nTell the choice : ");
        sf("%d",&choice);
        switch(choice){
            case 1 : mke_ll()       ;break;
            case 2 : add_start()    ;break;
            case 3 : add_end()      ;break;
            case 4 : add_posn()     ;break;
            case 5 : dlt_bgn()      ;break;
            case 6 : dlt_end()      ;break;
            case 7 : dlt_posn()     ;break;
            case 8 : display()      ;break;
            case 9 : pf("Exiting the program\n"); return 0;
            default : pf("Invalid option\n");
        }
    }
}