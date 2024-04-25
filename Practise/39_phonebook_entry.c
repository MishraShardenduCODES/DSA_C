#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PhonebookEntry {
    char name[50];
    char phoneNumber[15];
    struct PhonebookEntry* left;
    struct PhonebookEntry* right;
} PhonebookEntry;

PhonebookEntry* createEntry(char* name, char* phoneNumber) {
    PhonebookEntry* newEntry = (PhonebookEntry*)malloc(sizeof(PhonebookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->left = NULL;
    newEntry->right = NULL;
    return newEntry;
}

PhonebookEntry* insertEntry(PhonebookEntry* root, char* name, char* phoneNumber) {
    if (root == NULL) {
        return createEntry(name, phoneNumber);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insertEntry(root->left, name, phoneNumber);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertEntry(root->right, name, phoneNumber);
    }

    return root;
}

PhonebookEntry* searchEntry(PhonebookEntry* root, char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchEntry(root->left, name);
    } else {
        return searchEntry(root->right, name);
    }
}

void inorderTraversal(PhonebookEntry* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phoneNumber);
        inorderTraversal(root->right);
    }
}

int main() {
    PhonebookEntry* phonebook = NULL;

    phonebook = insertEntry(phonebook, "John", "1234567890");
    phonebook = insertEntry(phonebook, "Alice", "9876543210");
    phonebook = insertEntry(phonebook, "Bob", "8765432109");

    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    PhonebookEntry* result = searchEntry(phonebook, searchName);
    if (result != NULL) {
        printf("Contact found - Name: %s, Phone Number: %s\n", result->name, result->phoneNumber);
    } else {
        printf("Contact not found.\n");
    }

    printf("All contacts:\n");
    inorderTraversal(phonebook);

    return 0;
}
