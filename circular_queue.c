#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  pf printf
#define  sf scanf
#define N 5
int queue[N];
int front=-1,rear=-1;

void enqueue(){
    int a;
    pf("Enter the number to add : ");
    sf("%d",&a);
    if((rear+1)%N == front){
        pf("Queue is Full \n");
        return ;
    }else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=a;
    }else{
        rear=(rear+1)%N;
        queue[rear]=a;
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        pf("Queue is Empty \n");
        return;
    }else if(rear==front){
        pf("Dequeued element: %d \n",queue[rear]);
        rear=front=-1;
    }else{
        pf("Dequeued element: %d \n",queue[front]);
        front=(front+1)%N;
    }
}

void display(){
    if(rear == -1 && front == -1){
        pf("Queue is Empty \n");
    }else{
        int i=front;
        pf("Queue is : ");
        while(i != rear){
            pf("%d ",queue[i]);
            i=(i+1)%N;           
        }
        pf("%d \n",queue[rear]);
    }
}

void peek(){
    if(rear == -1 && front == -1){
        pf("Queue is Empty \n");
    }else{
        pf("Front element: %d \n",queue[front]);
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
