// 4.Write a C program to delete the odd numbered nodes
// from a singular linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=0;

void insertNode(int data) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=0;

    if (head==0) {
        head=newNode;
    } else {
        struct Node *temp=head;
        while (temp->next !=0) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void deleteOddNodes() {
    struct Node *prev=0, *temp=head;
    int cnt=1;
    while (temp !=0) {
        if (cnt % 2 !=0) {
            if (prev==0) {
                head=temp->next;
                free(temp);
                temp=head;
            } else {
                prev->next=temp->next;
                free(temp);
                temp=prev->next;
            }
        } else {
            prev=temp;
            temp=temp->next;
        }
        cnt++;
    }
}

void display() {
    struct Node *temp=head;
    while (temp !=0) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    int data;
    while (1) {
        printf("Enter data to insert (or -1 to stop): ");
        scanf("%d", &data);
        if (data==-1)
            break;
        insertNode(data);
    }

    printf("Original list: ");
    display();

    deleteOddNodes();
    
    printf("List after deleting odd numbered nodes: ");
    display();

    return 0;
}
