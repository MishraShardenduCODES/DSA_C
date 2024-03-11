#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf
#define N 5
int queue[N],front=-1,rear=-1;

void enqueue(){
    int a;
    pf("Tell the element : ");
    sf("%d",&a);
    if(rear==N-1){
        pf("It's Full \n");
        return;
    }else if(rear==-1 && front==-1){
        front=rear=0;
        queue[rear]=a;
    }else{
        rear+=1;
        queue[rear]=a;
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        pf("It's Empty \n");
        return ;
    }else if(rear==front){
        front=rear=-1;
    }else{
        front+=1;
    }
}

void display(){
    if(rear==-1 && front==-1){
        pf("It's Empty \n");
        return ;
    }else{
        for(int i=front;i<=rear;i++){
            pf("%d ",queue[i]);
        }
    }
}

void peek(){
    if(rear==-1 && front==-1){
        pf("It's a Empty \n");
    }else{
        pf("%d ",queue[front]);
        return ;
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