// 3.Write a C program to search for an element in the
// circular linked list by specifying the position
// and the item.

#include<stdio.h>
#include<stdlib.h>

#define pf printf
#define sf scanf

struct node{
    int data;
    struct node* next;
}*head=NULL, *tail=NULL;

void display(){
    struct node *temp = head;
    if (head == NULL) {
        pf("Circular linked list is empty\n");
        return;
    }
    do {
        pf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    pf("\n");
}

void insrt_bgn(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d", &newNode->data);
    if(head == NULL){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = newNode;
    }
    tail->next = head;
}

void insrt_end(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    pf("Tell an element : ");
    sf("%d", &newNode->data);
    if(head == NULL){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void insrt_posn(){
    int a;
    pf("Tell an element : ");
    sf("%d", &a);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    pf("Tell the position : ");
    sf("%d", &newNode->data);
    struct node* temp = head;
    if(head == NULL){
        pf("The list is empty\n");
        return;
    } else {
        int i=1;
        while(i < a-1 && temp->next != head){
            temp=temp->next;
            i+=1;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dlt_bgn(){
    if(head == NULL){
        pf("Circular linked list is empty, can't delete.\n");
    }else{
        struct node* temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void dlt_end(){
    if(head == NULL){
        pf("Circular linked list is empty, can't delete.\n");
    }else{
        struct node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
}

void srch_posn(){
    int posn;
    struct node *temp=head;
    pf("Tell the postion : ");
    sf("%d",&posn);
    int i=1;
    do{
        i++;
        temp=temp->next;
    }while(i<=posn && temp != head);

    pf("The element at the position is : %d\n",temp->data);
}

void srch_key(){
    struct node *temp=head;
    int key,i=1, found = 0;
    pf("Tell the element : ");
    sf("%d",&key);
    do{
        if(temp->data == key){
            pf("%d is present at the %d position\n",temp->data,i);
            found = 1;
            break;
        }
        temp=temp->next;
        i++;
    }while(temp != head);
    if(!found){
        pf("Element not found in the circular linked list\n");
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
        pf("6. Search by position\n");
        pf("7. Search by key\n");
        pf("8. Display\n");
        pf("9. Exit\n");
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
                srch_posn();
                break;
            case 7:
                srch_key();
                break;
            case 8:
                display();
                break;
            case 9:
                pf("Exiting program\n");
                exit(0);
            default:
                pf("Invalid choice\n");
        }
    }   
    return 0;
}
