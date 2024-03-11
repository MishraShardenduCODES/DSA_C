#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 

#define  pf printf
#define  sf scanf
#define n 1000

char str[n], str2[n];
int top = -1, start = -1;

char pop() {
    if (top == -1) {
        return 0 ;
    } else {
        return str[top--];
    }
}

int main() {
    pf("Tell : ");
    fgets(str, 1000, stdin);
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    for (int i = 0; str[i] != '\0'; i++) {
        top += 1;
    }
    for (int i = 0; top >= 0; i++) {
        str2[++start] = pop();
    }
    int stpr = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != str2[i]) {
            stpr = 1;
            break;
        }
    }
    if (stpr) {
        pf("Not");
    } else {
        pf("Yes");
    }
    return 0;
}
