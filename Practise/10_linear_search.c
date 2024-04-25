#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int*arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    int stpr = 1;
    scanf("%d",&key);
    int i;
    for(i=0;i<n;i++){
        if(key == arr[i]){
            stpr = 0;
            break;
        }
    }
    if(!stpr){
        printf("%d is at %d index",key,i);
    }else{
        printf("The element is not found");
    }
    free(arr);
}