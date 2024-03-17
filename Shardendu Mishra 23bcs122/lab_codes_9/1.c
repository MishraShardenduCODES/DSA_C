#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define pf printf
#define sf scanf

typedef struct node{
    int data;
    struct node *next;
}node;

void mke_ll(node**head,node**tail){
    node*newNode = (node*)malloc(sizeof(node));
    pf("Tell the number : ");
    sf("%d",&newNode->data);
    newNode->next=0;
    if(*head==0 && *tail == 0){
        *head=*tail=newNode;
    }else{
        (*tail)->next=newNode;
        (*tail)=(*tail)->next;
    }
}

void display(node**head){
    if(*head == NULL){
        pf("Its' empty");
    }else{
        node*temp = *head;
        while(temp != NULL){
            pf("%d ",temp->data);
            temp=temp->next;
        }
    }
    pf("\n");
}

void mrg_ll(node**head1,node**tail1,node**head2,node**tail2){
    if(*head1 == NULL || *head2 == NULL){
        pf("The ll is empty");
    }else{
        (*tail1)->next = *head2;
        *tail1 = *tail2; 
    }
}

int main() {
    node *head1 = NULL;
    node *tail1 = NULL;
    node *head2 = NULL;
    node *tail2 = NULL;

    for (int i = 0; i < 3; i++) {
        mke_ll(&head1, &tail1);
    }
    pf("First linked list: \n");
    display(&head1);

    for (int i = 0; i < 3; i++) {
        mke_ll(&head2, &tail2);
    }
    pf("Second linked list: \n");
    display(&head2);

    mrg_ll(&head1, &tail1, &head2, &tail2);

    pf("The merged linked list is : \n");
    display(&head1);
    return 0;
}