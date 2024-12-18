#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr = (int*)malloc(sizeof(int));
    //the pointer will be point to the first memory 
    //remember to convert void* malloc to what you want (int*)
    //sizeof(int) is how much the memory you want to use
    if (ptr == NULL){// check whether the pointer is NULL
        return 0;
    }
    *ptr = 23;//assign 
    printf("Value stored is %d\n",*ptr);
    free(ptr);// give the memory back to the computer
    return 0;

}