#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void Infix_Postfix(char infix[],char postfix[]){
    char stack[MAX_SIZE];
    int top = -1;
    int i,j;
    for(int i=0,j=0;infix[i] != '\0';i++){
        if(infix[i] == '('){
            stack[++top] = infix[i];
        }else if(isdigit(infix[i]) || isalpha(infix[i])){
            postfix[j++] = infix[i];
        }else if(isOperator(infix[i])){
            while(top >= 0 && precedence(stack[top]) >= precedence(infix[i])){
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; 
        }
    }
    while(top >= 0){
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}