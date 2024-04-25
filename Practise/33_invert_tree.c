#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} node;

node* createNode(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertNode(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val <= root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void swapNodes(node* left, node* right) {
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
}

void mirrorTree(node* left, node* right) {
    if (left == NULL && right == NULL) return;
    if (left != NULL && right != NULL) {
        swapNodes(left, right);
        mirrorTree(left->left, right->right);
        mirrorTree(left->right, right->left);
    } else if (left != NULL) {
        mirrorTree(left->left, NULL);
        mirrorTree(left->right, NULL);
    } else if (right != NULL) {
        mirrorTree(NULL, right->right);
        mirrorTree(NULL, right->left);
    }
}

node* invertTree(node* root) {
    if (root == NULL) return NULL;
    mirrorTree(root->left, root->right);
    return root;
}

void inOrderTraversal(node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->val);
        inOrderTraversal(root->right);
    }
}

int main() {
    node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 17);
    root = insertNode(root, 72);
    root = insertNode(root, 12);
    root = insertNode(root, 23);
    root = insertNode(root, 54);
    root = insertNode(root, 76);
    root = insertNode(root, 9);
    root = insertNode(root, 14);
    root = insertNode(root, 19);
    root = insertNode(root, 67);

    printf("Original tree (in-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    root = invertTree(root);

    printf("Inverted tree (in-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}