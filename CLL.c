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
};
struct node*tail=0,*head=0;

void display(){
    struct node*temp=head;
    if(head==0){
        pf("Empty\n");
    }else{
        while(temp->next!=tail->next){
            pf("%d ",temp->data);
            temp=temp->next;
        }
        pf("%d \n",temp->data);
    }
}

void dlt_bgn(){
    struct node*temp;
    temp=head;
    if(head==0){
        pf("Empty");
    }else if(tail->next==head->next){
        head=0;
    }else{
        head=head->next;
    }
    free(temp);
}

void dlt_end(){
    struct node*temp=head,*prvNode;
    prvNode=head;
    temp=temp->next;
    while(temp->next != tail->next){
        prvNode=prvNode->next;
        temp=temp->next;
    }
    prvNode->next=head;
    tail=prvNode;
    free(temp);
}

void dlt_posn(){
    struct node*temp=head,*nextNode=head;
    int i=1,posn;
    pf("Tell the position : ");
    sf("%d",&posn);
    if(posn==1){
        dlt_bgn();
    }else{
        nextNode=nextNode->next;
        while(i<posn-1){
            nextNode=nextNode->next;
            temp=temp->next;
            i++;
        }
        temp->next=nextNode->next;
        free(nextNode);
    }
}

void insrt_bgn(){
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the data : ");
    sf("%d",&newNode->data);
    if(head==0){
        head=tail=newNode;
        // if this line is not inserted it will cause it to //
        // have an infinte link as tail wont be linked to anyhting //
        //       |
        //      |
        //      V
        tail->next=newNode;
    }else{
        newNode->next=tail->next;
        tail->next=newNode;
        head=newNode;
    }
}

void insrt_end(){
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(head==0){
        insrt_bgn();
    }else{
        pf("Tell the data : ");
        sf("%d",&newNode->data);
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}

void insrt_posn(){
    struct node*temp=head,*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(head==0){
        insrt_bgn();
    }else{
        int posn;
        pf("Tell the element and the position : ");
        sf("%d%d",&newNode->data,&posn);
        int i=1;
        while(i<posn-1 ){
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void mke_cll(){
    struct node*temp,*newNode;
    head=0;
    while(1){
        int a;
        pf("Press 1 to stop : ");
        sf("%d",&a);
        if(a==1){
            break;
        }else{
            newNode=(struct node*)malloc(sizeof(struct node));
            int n;
            pf("Tell an element : ");
            sf("%d",&newNode->data);
            newNode->next=0;
            if(head==0){
                head=temp=tail=newNode;
            }else{
                newNode->next=tail->next;
                temp->next=newNode;
                tail=temp=newNode;
            }
            tail->next=head;
        }
    }
}

int main(){
    while(1){
        int a;
        pf("\n1.) Make a circular ll \n2.) Exit \n3.) Display \n4.) Insert at the beggining \n5.) Insert at the end \n6.) Insert at the position \n7.) Delete at the beggining \n8.) Delete at the end \n9.) Delete at the position  \nChoose what to do : ");
        sf("%d",&a);
        switch(a){
            case 1 : mke_cll()              ;break;
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