#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

inline int isOpr(char op){
    return (op == '+' || op == '-' || op == '/' || op == '*');
}

int precedence(char op){
    switch(op){
        case '+': return 1; 
        case '-': return 1; 
        case '*': return 2; 
        case '/': return 2; 
        default : return 0; 
    }
}

void OperatorPrecedence(){
    char expr[MAX_SIZE];
    printf("Tell the expression : ");
    fgets(expr,MAX_SIZE,stdin);

    printf("Operator Precedence : ");
    for(int i = 0;expr[i] != '\0';i++){
        if (isOperator(expr[i])) {
            printf("%c : %d\n", expr[i], precedence(expr[i]));
        }
    }
}

int main() {
    printOperatorPrecedence();
    return 0;
}