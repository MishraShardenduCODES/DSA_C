#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int grade;
    struct Student* left;
    struct Student* right;
} Student;

Student* createStudent(const char* name, int grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->grade = grade;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

Student* insertStudent(Student* root, const char* name, int grade) {
    if (root == NULL) {
        return createStudent(name, grade);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insertStudent(root->left, name, grade);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertStudent(root->right, name, grade);
    }

    return root;
}

Student* searchStudent(Student* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchStudent(root->left, name);
    } else {
        return searchStudent(root->right, name);
    }
}

void inorderTraversal(Student* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Grade: %d\n", root->name, root->grade);
        inorderTraversal(root->right);
    }
}

void findMinMaxGrades(Student* root, int* minGrade, int* maxGrade) {
    if (root == NULL) {
        return;
    }
    if (root->grade < *minGrade) {
        *minGrade = root->grade;
    }
    if (root->grade > *maxGrade) {
        *maxGrade = root->grade;
    }
    findMinMaxGrades(root->left, minGrade, maxGrade);
    findMinMaxGrades(root->right, minGrade, maxGrade);
}

int main() {
    Student* root = NULL;

    root = insertStudent(root, "John", 85);
    root = insertStudent(root, "Alice", 92);
    root = insertStudent(root, "Bob", 78);

    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    Student* result = searchStudent(root, searchName);
    if (result != NULL) {
        printf("Student found - Name: %s, Grade: %d\n", result->name, result->grade);
    } else {
        printf("Student not found.\n");
    }

    printf("All students:\n");
    inorderTraversal(root);

    int minGrade = 100, maxGrade = 0;
    findMinMaxGrades(root, &minGrade, &maxGrade);
    printf("Highest performing student: %d\n", maxGrade);
    printf("Lowest performing student: %d\n", minGrade);

    return 0;
}
