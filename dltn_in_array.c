//deletion at any sepcific position//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf

int main(){
    int arr[5] =  {1,2,3,4,5},arr2[4],j=0,a,stpr;  
        for(int i=0;i<5;i++){
        pf(" %d ",arr[i]);
    }
    pf("\n");
    pf("Tell the postion from which we have to remove : ");
    sf("%d",&a);
    for(int i=0;i<5;i++){
        if(i==a){
            continue;
        }
        arr2[j]=arr[i];
        j+=1;
    }
    pf("Tell the array : ");
    for(int i=0;i<j;i++){
        pf(" %d ",arr2[i]);
    }
    return 0;
}