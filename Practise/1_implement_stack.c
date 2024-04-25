#include<stdio.h>
#include<math.h>
#define Mx 5
int arr[Mx];
int top = -1;

int isEmpty(){
    if(top == -1) return 1;
    return 0;
}

int isFull(){
    if(top == Mx-1) return 1;
    return 0;
}

void push(int data){
    if(isFull()){
        printf("It's already Full");
        return;
    }
    top += 1;
    arr[top] = data;
}

void pop(){
    if(isEmpty()){
        printf("It's empty");
        return;
    }
    printf("%d is popped\n",arr[top]);
    top -= 1;
}

void peek(){
    if(isEmpty()){
        printf("It's empty");
        return;
    }
    printf("%d \n",arr[top]);
}


void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Push element onto stack\n");
    printf("2. Pop element from stack\n");
    printf("3. Peek at the top element\n");
    printf("4. Check if the stack is full\n");
    printf("5. Check if the stack is empty\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, data;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push onto stack: ");
                scanf("%d", &data);
                push(data);
                break;
                
            case 2:
                printf("Popping element from stack.\n");
                pop();
                break;
                
            case 3:
                printf("Peeking at the top element of stack.\n");
                peek();
                break;
                
            case 4:
                if (isFull()) {
                    printf("The stack is full.\n");
                } else {
                    printf("The stack is not full.\n");
                }
                break;
                
            case 5:
                if (isEmpty()) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
                
            case 6:
                printf("Exiting the program.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
