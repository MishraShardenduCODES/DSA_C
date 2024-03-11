#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 

#define  pf printf
#define  sf scanf
#define n 1000

int top=-1,s[n];
void push(){
    if(top==n-1){
        pf("It's full\n");
    }else{
        int a;
        pf("Tell : ");
        sf("%d",&a);
        top+=1;
        s[top]=a;
    }
}

void pop(){
    if(top == -1){
        pf("It's Empty");
    }else{
        pf("%d is popped",s[top]);
        top-=1;
    }
}

void display(){
    if(top==-1){
        pf("Empty \n");
    }else{
        int i=0;
        while(i<=top){
            pf("%d ",s[i]);
            i+=1;
        }
    }
}
int main(){
    int a ;
    do{
        pf("Tell : ");
        sf("%d",&a);
        switch(a){
            case 1 : push();break;
            case 2 : pop();break;
            case 3 : display();break;
            case 4 : exit(1);
            default: pf("Invalid \n");
        }
    }while(a!=4);
}