#include<stdio.h>
#include<stdlib.h>
#define N 5
int deque[N], front = -1, rear = -1;

void display() {
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d ", deque[i]);
}
void peek() {
    printf("%d ", deque[front]);
}
void enque_frnt() {
    int num;
    printf("Tell the element : ");
    scanf("%d", &num);
    if ((rear + 1) % N == front) {
        printf("Queue is full \n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = num;
    } else if (front == 0) {
        front = N - 1;
        deque[front] = num;
    } else {
        front--;
        deque[front] = num;
    }
}
void enque_rear() {
    int num;
    printf("Tell the element : ");
    scanf("%d", &num);
    if (front == -1 || rear == -1) {
        front = rear = 0;
        deque[rear] = num;
    } else if (rear == N - 1) {
        rear = 0;
        deque[rear] = num;
    } else {
        rear++;
        deque[rear] = num;
    }
}
void deque_frnt() {
    if (front == -1 && rear == -1) {
        printf("It's Empty \n");
    } else if (front == rear) {
        printf("%d has been Dequed", deque[front]);
        rear = front = -1;
    } else if (front == N - 1) {
        printf("%d has been Dequed", deque[front]);
        front = 0;
    } else {
        printf("%d has been Dequed", deque[front]);
        front += 1;
    }
}
void deque_rear(){
    if(front == -1 && rear == -1) {
        printf("It's Empty \n");
    }else if(rear == 0) {
        printf("%d has been Dequed", deque[rear]);
        rear = N - 1;
    }else if(rear == front) {
        printf("%d has been Dequed", deque[rear]);
        rear = front = -1;
    }else{
        printf("%d has been Dequed", deque[rear]);
        rear -= 1;
    }
}
int main(){
    int choice;
    while (1){
        printf("\n1. Display\n2. Peek\n3. Enqueue Front\n4. Enqueue Rear\n5. Dequeue Front\n6. Dequeue Rear\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display()   ;break;
            case 2:
                peek()      ;break;
            case 3:
                enque_frnt();break;
            case 4:
                enque_rear();break;
            case 5:
                deque_frnt();break;
            case 6:
                deque_rear();break;
            case 7:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice\n");break;
        }
    }
    return 0;
}