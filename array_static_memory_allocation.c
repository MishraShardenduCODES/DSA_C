#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf
#define N 100
int a;

int top = -1;
int stack[N];

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(top == a-1){
        return 1;
    }else{
        return 0;
    }
}

void display(){
    if(isEmpty()){
        pf("Its Empty,Nothing to display.\n");
        return;
    }else{
        for(int i = top; i >= 0; i--){
            pf("| %d |\n", stack[i]);
        }
    }
}

void peek(){
    if(isEmpty()){
        pf("Its Empty,Nothing to display.\n");
        return;
    }else if(isFull()){
        pf("It's completely full can't add more items. \n");
        return;
    }
    pf("%d ",stack[top]);
}

void push(){
    if(isFull()){
        pf("Its completely Full\n");
        return;
    }
    int x;
    pf("Tell the element to push : ");
    sf("%d",&x);
    ++top;
    stack[top]=x;
}

void pop(){
    if(isEmpty()){
        pf("Its completely Empty\n");
        return;
    }
    pf("| %d |",stack[top]);
    --top;
}

int main(){
    pf("Tell the size : ");
    sf("%d",&a);
    stack[a];
    while(1){
        int choice;
        pf("\n1.) Push\n2.) Pop\n3.) Peek\n4.) Display\n5.) Exit\n");
        pf("Enter your choice: ");
        sf("%d", &choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: pf("Invalid choice\n");
        }
    }
    return 0;
}
