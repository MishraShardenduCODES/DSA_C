#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bool solve(node* root, int min, int max) {
    if(root == NULL) return true;

    if(root->data <= min || root->data > max){
        return (solve(root->left,min,root->data) && solve(root->left,root->data,max));
    }
}

bool isValidBST(node* root) {
    return solve(root, -2147483648, 2147483647); // INT_MIN and INT_MAX
}

int main() {
    node* root  = createnode(4);
    root->left  = createnode(2);
    root->right = createnode(6);
    root->left->left   = createnode(1);
    root->left->right  = createnode(3);
    root->right->left  = createnode(5);
    root->right->right = createnode(7);
    if (isValidBST(root)) {
        printf("The binary tree is a valid binary search tree.\n");
    } else {
        printf("The binary tree is not a valid binary search tree.\n");
    }
    return 0;
}
