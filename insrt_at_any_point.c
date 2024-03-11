//insertion at any sepcific position//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf
#define Max_size 100
int cntr=5;

int main(){
    int arr[Max_size] = {1,2,3,4,5};
    pf("The array is : ");
    for(int i=0;i<cntr;i++){
        pf(" %d ",arr[i]);
    }
    pf("\n");
    int a,b;
    pf("Tell the number and the position : ");
    sf("%d%d",&a,&b);
    if(b>Max_size){
        pf("Cant push range out of array");
        return 0;
    }else if(cntr==Max_size){
        pf("Array is full");
        return 0;
    }
    for(int i=cntr;i>=b;i--){
        arr[i+1]=arr[i];
    }
    arr[b]=a;
    cntr+=1;
    pf("The array is : ");
    for(int i=0;i<cntr;i++){
        pf(" %d ",arr[i]);
    }
}