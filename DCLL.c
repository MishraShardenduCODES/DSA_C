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
    struct node*prev;
    struct node*next;
};
struct node*head=0,*tail;

void display(){
    struct node*temp=head;
    while(temp!=tail){
        if(head==0){
            pf("Its Empty\n");
            break;
        }else{
            pf("%d ",temp->data);
            temp=temp->next;
        }
    }
    pf("%d ",temp->data);
}

void mke_dcll(){
    while(1){
        int a;
        pf("Press 0 to stop : ");
        sf("%d",&a);
        if(a==0){
            break;
        }
        struct node*newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        pf("Tell the data : ");
        sf("%d",&newNode->data);
        if(head==0){
            head=tail=newNode;
            newNode->next=newNode;
            newNode->prev=newNode;
        }else{
            newNode->prev=tail;
            newNode->next=head;
            tail->next=newNode;
            head->prev=newNode;
            tail=newNode;
        }
    }
}

void insrt_bgn(){
    if(head==0){
        mke_dcll();
        return ;
    }
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the data : ");
    sf("%d",&newNode->data);
    newNode->next=head;
    newNode->prev=tail;
    tail->next=newNode;
    head->prev=newNode;
    head=newNode;
}

void insrt_end(){
    if(head==0){
        mke_dcll();
        return ;
    }
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the data : ");
    sf("%d",&newNode->data);
    newNode->prev=tail;
    newNode->next=head;
    tail->next=newNode;
    head->prev=newNode;
    tail=newNode;
}

void insrt_posn(){
    int posn,count=0;
    struct node*newNode,*temp=head,*nextNode;
    while(temp!=tail){
        temp=temp->next;
        count++;
    }
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the position : ");
    sf("%d",&posn);
    if(posn==0){
        insrt_bgn();
    }else if(posn==count){
        insrt_end();
    }else if(posn>count){
        pf("Position is not available");
        return;
    }else{
        pf("Tell the data : ");
        sf("%d",&newNode->data);
        int i=1;
        temp=head;
        nextNode=head->next;
        while(i<posn-1){
            nextNode=nextNode->next;
            temp=temp->next;
            i++;
        }
        newNode->next=nextNode;
        newNode->prev=temp;
        nextNode->prev=newNode;
        temp->next=newNode;
    }
}

void dlt_bgn(){
    if(head==0){
        pf("It's Empty\n");
    }else if(head->next==head){
        free(head);
    }else{
        struct node*temp=head,*prvNode=head;
        temp=temp->next;
        temp->prev=tail;
        tail->next=temp;
        head=temp;
        free(prvNode);
    }
}

void dlt_end(){
    if(head==0){
        pf("It's Empty\n");
    }else if(head->next==head){
        free(head);
    }else{
        struct node*prvNode,*temp;
        temp=prvNode=head;
        temp=temp->next;
        while(temp!=tail){
            prvNode=prvNode->next;
            temp=temp->next;
        }
        prvNode->next=head;
        head->prev=prvNode;
        tail=prvNode;
        free(temp);
    }
}

void dlt_posn(){
    struct node *temp, *prvNode, *nextNode;
    int posn, count = 0;
    
    if(head == 0){
        pf("It's empty\n");
        return;
    }
    
    temp = head;
    while(temp != tail){
        temp = temp->next;
        count++;
    }
    
    pf("Tell the position to delete: ");
    sf("%d", &posn);
    
    if(posn == 0){
        dlt_bgn();
    } else if(posn == count){
        dlt_end();
    } else if(posn > count){
        pf("Position is not available\n");
        return;
    } else {
        temp = head;
        nextNode = temp->next;
        for(int i = 1; i < posn; i++){
            temp = nextNode;
            nextNode = nextNode->next;
        }        
        prvNode = temp->prev;
        prvNode->next = nextNode;
        nextNode->prev = prvNode;
        free(temp);
    }
}


int main(){
    while(1){
        int a;
        pf("\n1.) Make a circular ll \n2.) Exit \n3.) Display \n4.) Insert at the beggining \n5.) Insert at the end \n6.) Insert at the position \n7.) Delete at the beggining \n8.) Delete at the end \n9.) Delete at the position  \nChoose what to do : ");
        sf("%d",&a);
        switch(a){
            case 1 : mke_dcll()             ;break;
            case 2 : pf("Exiting Program\n");exit(EXIT_SUCCESS);  
            case 3 : display()              ;break;
            case 4 : insrt_bgn()            ;break;
            case 5 : insrt_end()            ;break;
            case 6 : insrt_posn()           ;break;
            case 7 : dlt_bgn()              ;break;
            case 8 : dlt_end()              ;break;
            case 9 : dlt_posn()             ;break;             
        }
    }
}