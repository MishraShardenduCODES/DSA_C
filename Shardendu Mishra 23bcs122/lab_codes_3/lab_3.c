// 3.Write a C program to demonstrate the various
// operations of the circular queue such as enque,
// deque and display. The program should be menu
// driven
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define pf printf
#define sf scanf
#include<math.h>
#define n 10

int q[n],f=-1,r=-1;

void enqueue(){
    if(f==(r+1)%n){
        pf("It's full \n");
    }else {
        if(f == -1 && r == -1){
            f=r=0;
        }else{
            r=(r+1)%n;
        }
        int a;
        pf("Tell the element : ");
        sf("%d",&a);
        q[r]=a;
    }
}
void dequeue(){
    if(r == -1){
        pf("It's empty");
    }else{
        pf("%d dequeued from the list \n",q[f]);
        if(f==r){
            f = r = -1 ;
        }else{
            f=(f+1)%n;
        }
    }
}
void display(){
    if(r == f){
        pf("It's empty");
    }else{
        int a=f;
        while(a != r){
            pf("%d ",q[a]);
            a=(a+1)%n;
        }
        pf("%d ",q[a]);
    }
}
int main() {
    int choice;
    do{
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 to 4.\n");
        }
    }while (choice != 4);

    return 0;
}