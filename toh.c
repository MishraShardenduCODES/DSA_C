#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 

#define  pf printf
#define  sf scanf

void toh(char src, char aux, char dst, int n) {
    if (n == 1) {
        pf("Move from %c to %c\n", src, dst);
        return;
    }
    toh(src, dst, aux, n - 1); 
    pf("Move from %c to %c\n", src, dst); 
    toh(aux, src, dst, n - 1); 
}


int main() {
    int n;
    char a = 'A', b = 'B', c = 'C'; // Initialize pegs
    pf("Tell how many you want : ");
    sf("%d", &n);
    toh(a, b, c, n);
    return 0;
}
