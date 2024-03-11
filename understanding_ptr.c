// #include <stdio.h>
// int main() {
//     int num = 10;
//     int *ptr;    // Declare a pointer variable
//     ptr = &num;  // Assign the address of num to ptr
//     printf("Address of num: %p\n", ptr);
//     printf("Value of num: %d\n", *ptr);  // Dereference ptr to access the value of num
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     int *ptr = arr;  // Point to the first element of the array
//     printf("First element of the array: %d\n", *ptr);  // Access the first element using ptr
//     ptr++;  // Move to the next element
//     printf("Second element of the array: %d\n", *ptr);  // Access the second element using ptr
//     int *ptr=arr;
//     for(int i=0;i<5;i++){
//         printf("%d  ",*(ptr+i));
//     }
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int num = 10;
//     int *ptr1 = &num;  // Pointer to num
//     int **ptr2 = &ptr1;  // Pointer to ptr1
//     printf("Value of num: %d\n", **ptr2);  // Dereference ptr2 twice to access the value of num
//     return 0;
// }

// #include<stdio.h>
// #define pf printf
// #define sf scanf
// int main(){
//     int a=10;
//     int*ptr=&a;
//     pf("%d ",*ptr);
//     (*ptr)++;
//     pf("%d ",*ptr);
//     pf("%d ",a);
//     ptr++;
//     pf("%d ",*ptr);
//     int arr[5]={10,20,30,40,50};
//     int*p=arr;
//     pf("%d ",*p);
//     p++;
//     pf("%d ",*p);
//     *(p++);
//     pf("%d ",*p);
//     return 0;
// }