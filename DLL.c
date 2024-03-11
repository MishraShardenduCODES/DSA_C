// ALL OPERATION IN DOUBLE LINKED LIST IMPLEMENTATION //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf

struct node{
    struct node* prv;
    int data;
    struct node* next;
};

struct node* head = 0;
struct node* tail = 0;

// void rvrs(){
//     struct node*temp=head;
//     int num=0;
//     while(temp->next!=0){
//         num+=1;
//     }
//     for(int i=0;i<num;i++){
//         temp=head;
//         for(int j=0;j<num-i;j++){
//             struct node* temp1 = temp->next;
//             temp->next = temp->prv;
//             temp->prv = temp1;
//             temp = temp1;
//         }
//     }
// }

void display(){
    struct node* temp = head;
    while (temp != 0){
        pf("%d ", temp->data);
        temp = temp->next;
    }
}

void mke_dll(){
    while(1){
        struct node* newNode;
        int a;
        pf("Press 1 to stop : ");
        sf("%d", &a);
        if(a == 1){
            break;
        }else{
            newNode = (struct node*)malloc(sizeof(struct node));
            pf("Enter data : ");
            sf("%d", &newNode->data);
            newNode->prv =0;
            newNode->next=0;
            if(head == 0){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                newNode->prv = tail;
                tail = newNode;
            }
        }
        pf("\n");
    }
}

void insrt_bgn(){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    pf("Tell the data : ");
    sf("%d",&newNode->data);
    newNode->prv=0;
    newNode->next=0;
    if(head==0){
        head=newNode;
    }else{
        head->prv=newNode;
        newNode->next=head;
        head=newNode;
    }

}

void insrt_end(){
    if(head==0){
        insrt_bgn();
    }else{
        struct node* newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        pf("Tell the data : ");
        sf("%d",&newNode->data);
        newNode->prv=0;
        newNode->next=0;
        tail->next=newNode;
        newNode->prv=tail;
        tail=newNode;
    }
}
void insrt_posn(){
    struct node*temp=head;
    int count=0;
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    pf("Tell position and the number : \n");
    free(temp);
    int a,b;
    sf("%d%d",&a,&b);
    if(b<=0){
        pf("\nInvalid\n");
    }else if(b==1){
        insrt_bgn();
    }else if(b>count){
        pf("This position is not available \n");
        return;
    }else if(b==count){
        insrt_end();
    }else{
        int i=0;
        struct node* newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=a;
        newNode->prv=0;
        newNode->next=0;
        temp=head;
        while(i<b-1){
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        newNode->prv=temp;
        temp->next=newNode;
        newNode->next->prv=newNode;
    }
}

void dlt_start(){
    struct node*temp;
    if(head==0){
        pf("Empty list");
    }else{
        temp=head;
        head=head->next;
        head->prv=0;
        free(temp);
    }
}

void dlt_end(){
    struct node*temp;
    if(head==0){
        pf("Empty list");
    }else{
        temp=tail;
        tail=tail->prv;
        tail->next=0;
        free(temp);
    }  
}

void dlt_posn(){
    struct node*temp;
    if(head==0){
        pf("Empty list");
    }else{
        int posn,i=1;
        pf("Tell posn to delete : ");
        sf("%d",&posn);
        temp=head;
        while(i<posn){
            temp=temp->next;
            i++;
        }
        temp->prv->next=temp->next;
        temp->next->prv=temp->prv;
        free(temp);
    }
}

int main(){
    int a;
    while(1){
        pf("\nChoose an option \n1.) Make a Double Linked List \n2.) Display \n3.) Insert at the start \n4.) Press 4 to exit the program \n5.) Insert at the end \n6.) Insert at any position \n7.) Delete from start \n8.) Delete from end \n9.) Delete from any position \n10.) Reverse the list \nYour Choice :");
        sf("%d",&a);
        switch (a){
            case 1 : mke_dll()         ;break;
            case 2 : display()         ;break;
            case 3 : insrt_bgn()       ;break;
            case 4 : exit(EXIT_SUCCESS);break;
            case 5 : insrt_end()       ;break;
            case 6 : insrt_posn()      ;break;
            case 7 : dlt_start()       ;break;
            case 8 : dlt_end()         ;break;
            case 9 : dlt_posn()        ;break;
            // case 10: rvrs()            ;break;
            default : pf("\nInvalid\n");break;
        }
    }
}