//deletion at any sepcific position//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <stdbool.h>
#include <limits.h> 
#define  pf printf
#define  sf scanf
int count=5;
 
int main(){
    int arr[5] =  {1,2,3,4,5},a;  
    for(int i=0;i<count;i++){
        pf(" %d ",arr[i]);
    }
    pf("\n");
    pf("Tell the postion from which we have to remove : ");
    sf("%d",&a);
    for(int i=a;i<count;i++){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    count-=1;
    for(int i=0;i<count;i++){
        pf(" %d ",arr[i]);
    }
    return 0;
}