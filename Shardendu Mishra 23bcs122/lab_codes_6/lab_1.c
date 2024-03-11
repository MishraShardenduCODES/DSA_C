// 1.Write a C program to search for an element in the
// singly linked list by specifying the position and
// the item.

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#define pf printf
#define sf scanf

struct node{
    int data;
    struct node*next;
}*head=0,*tail=0,*temp,*newNode;


void display(){
    temp=head;
    while(temp->next != 0){
        pf("%d ",temp->data);
        temp=temp->next;
    }
    pf("%d ",temp->data);
}

void insrt_bgn(){
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d",&newNode->data);
    if(head == 0){
        head=tail=newNode;
        head->next=0;
    }else{
        newNode->next=head;
        head=newNode;
    }
}

void insrt_end(){
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d",&newNode->data);
    if(head == 0){
        head=tail=newNode;
        head->next=0;
    }else{
        tail->next=newNode;
        newNode->next=0;
        tail=newNode;
    }
}

void insrt_posn(){
    int a;
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d",&newNode->data);
    pf("Tell the position : ");
    sf("%d%d",&newNode->data,a);
    if(a==1){
        insrt_bgn();
    }else{
        int i=1;
        temp=head;
        while(i<a-1 && temp->next != 0){
            temp=temp->next;
            i+=1;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void dlt_bgn(){
    if(head == 0){
        pf("It's empty");
    }else{
        temp=head;
        head=head->next;
        free(temp);
    }
}

void dlt_end(){
    if(head == 0){
        pf("It's empty");
    }else{
        struct node * temp2;
        temp=temp2=head;
        temp2=temp2->next;
        while(temp2->next!=0){
            temp=temp->next;
            temp2=temp2->next;
        }
        tail->next=0;
        free(temp2);
    }
}

void dlt_posn(){
    int a;
    pf("Tell a position : ");
    sf("%d",&a);
    if(a==1){
        dlt_bgn();
    }else{
        int i=1;
        struct node * temp2;
        temp=head;
        while(i<a-1 && temp->next != 0){
            temp2=temp;
            temp=temp->next;
            i+=1;
        }
        temp2->next=0;
        free(temp);
    }   
}

void srch_posn(){
    int posn;
    struct node *temp=head;
    pf("Tell the postion : ");
    sf("%d",&posn);
    int i=1;
    while(i<=posn-1 && temp != 0){
        i++;
        temp=temp->next;
    }
    pf("The element at the position is : %d",temp->data);
}

void srch_key(){
    struct node *temp=head;
    int key,i=0;
    pf("Tell the element : ");
    sf("%d",&key);
    int stpr=1;
    while(temp!=0){
        ++i;
        if(temp->data == key){
            pf("%d is present at the %d position",temp->data,i);
            stpr=0;
            break;
        }
        temp=temp->next;
    }
    if(stpr==1){
        pf("element not there ");
    }
}

int main() {
    int choice;
    while (1) {
        pf("\nMenu:\n");
        pf("1. Insert at the beginning\n");
        pf("2. Insert at the end\n");
        pf("3. Insert at specified position\n");
        pf("4. Delete at the beginning\n");
        pf("5. Delete at the end\n");
        pf("6. Delete at specified position\n");
        pf("7. Display\n");
        pf("8. Exit\n");
        pf("9. Search a key\n");
        pf("10. Search a position\n");
        pf("Enter your choice: ");
        sf("%d", &choice);
        
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
                display();
                break;
            case 8:
                pf("Exiting program\n");
                exit(0);
            case 9:
                srch_key();
                break;
            case 10:
                srch_posn();
                break;
            default:
                pf("Invalid choice\n");
        }
    }   
    return 0;
}