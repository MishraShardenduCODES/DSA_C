// 2.Write a C program to check whether a given string
// is a palindrome or not using the linked lists.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pf printf

struct node {
    char data;
    struct node *next;
} *temp, *head, *tail, *newNode;

char str[1000];

void insrt_bgn(char ch) {
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = ch;
    newNode->next = NULL; 
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int main() {
    pf("Tell an element : ");
    fgets(str, 1000, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i]=='\0'){
            continue;
        }
        insrt_bgn(str[i]);
    }
    int i=0,stpr=0;
    temp = head;
    while (temp != '\0') {
        if(str[i]!=temp->data){
            stpr=1;
            break;
        }
        i+=1;
        temp = temp->next;
    }
    if(stpr){
        pf("It's not a palindrome");
    }else{
        pf("It's a palindrome");
    }
    return 0;
}

