#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


bool areIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->key == root2->key) 
    && areIdentical(root1->left, root2->left) 
    && areIdentical(root1->right, root2->right);
}

int main() {
    Node* root1  = createNode(4);
    root1->left  = createNode(2);
    root1->right = createNode(6);
    root1->left->left   = createNode(1);
    root1->left->right  = createNode(3);
    root1->right->left  = createNode(5);
    root1->right->right = createNode(7);

    Node* root2  = createNode(4);
    root2->left  = createNode(2);
    root2->right = createNode(6);
    root2->left->left   = createNode(1);
    root2->left->right  = createNode(3);
    root2->right->left  = createNode(5);
    root2->right->right = createNode(7);

    if(areIdentical(root1, root2)) {
        printf("The two BSTs are identical.\n");
    }else{
        printf("The two BSTs are not identical.\n");
    }

    return 0;
}