// 3.Write a C program to convert a given infix
// expression to its postfix equivalent using the
// stack. Implement the stack using the singly linked
// list data structure.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new node
struct StackNode* newNode(char data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push an item to the stack
void push(struct StackNode** root, char data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop an item from the stack
char pop(struct StackNode** root) {
    if (isEmpty(*root))
        return '\0';
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to return the top item from the stack
char peek(struct StackNode* root) {
    if (isEmpty(root))
        return '\0';
    return root->data;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix) {
    int i, k;
    struct StackNode* stack = NULL;
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isOperand(infix[i])) {
            infix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++k] = pop(&stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(&stack);
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[++k] = pop(&stack);
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(stack))
        infix[++k] = pop(&stack);
    infix[++k] = '\0';
    printf("Postfix expression: %s\n", infix);
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix);
    return 0;
}
