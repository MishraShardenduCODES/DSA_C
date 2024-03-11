#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf

struct node{
    int data;
    struct node*next;
}*head=0,*tail=0,*temp;

void enqueue(){
    int a;
    pf("Tell the element to add : ");
    sf("%d",&a);
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=0;
    newNode->data=a;
    if(head==0 && tail==0){
        head=tail=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    }
}

void dequeue(){
    struct node*temp=head;
    if(head==0 && tail==0){
        pf("It's empty \n");
        return ;  
    }else{
        head=head->next;
        pf("%d ",temp->data);
        free(temp);
    }
}

void display(){
    struct node*temp=head;
    if(head==0 && tail==0){
        pf("It's empty \n");
        return ;
    }else{
        while(temp!=tail){
            pf("%d ",temp->data);
            temp=temp->next;
        }
        pf("%d ",temp->data);
    }
}

void peek(){
    if(head==0 && tail==0){
        pf("It's empty \n");
        return ;
    }else{
        pf("%d ",tail->data);
    }
}

int main(){
    int choice;
    while (1){
        pf("\n1. Enqueue\n");
        pf("2. Dequeue\n");
        pf("3. Display\n");
        pf("4. Peek\n");
        pf("5. Exit\n");
        pf("Enter your choice: ");
        sf("%d", &choice);
        switch (choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            pf("Invalid choice \n");
        }
    }
    return 0;
}