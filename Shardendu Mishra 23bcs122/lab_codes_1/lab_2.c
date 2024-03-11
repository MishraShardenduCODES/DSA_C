#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to check if stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push a character onto the stack
void push(char item) {
    if (!isFull()) {
        stack[++top] = item;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop a character from the stack
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

// Function to check if a string is palindrome using stack
int isPalindrome(char* str) {
    unsigned length = strlen(str);

    // Push characters of the first half of the string onto the stack
    for (unsigned i = 0; i < length / 2; ++i) {
        push(str[i]);
    }

    // Check if the second half of the string matches the characters popped from the stack
    for (unsigned i = (length + 1) / 2; i < length; ++i) {
        if (str[i] != pop()) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Palindrome
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}
