#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} node;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int val) {
    if (root == NULL) {
        root = createNode(val);
    } else {
        if (val <= root->val) {
            root->left = insertNode(root->left, val);
        } else {
            root->right = insertNode(root->right, val);
        }
    }
    return root;
}

void postorderTraversal(node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->val);
    }
}

void preorderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
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

    printf("Preorder traversal : ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal : ");
    postorderTraversal(root);
    printf("\n");

    printf("Inorder traversal : ");
    InorderTraversal(root);
    printf("\n");

    return 0;
}

// 50 17 72 12 23 9 14 19  54 76 67