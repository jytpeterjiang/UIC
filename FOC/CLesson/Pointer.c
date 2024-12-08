#include<stdio.h>
#include<string.h>
//if I need a function to change the exact value in variables
void swap(char *pA,char *pB){// sent the location in
    char temp = *pA;
    *pA = *pB;
    *pB = temp;
}
int main(){
    int x;
    int *p1;
    char *p2;// different type of variables need different type of pointers
    p1 = &x;// remember to initialize, after that, *p1 = x, p1 = &x
    // when you do any operation on *p1, the x will change as same
    // when you do any operation on p1, the &x will change as same
    // *p1++ means first add one to p1 then take the new value of p1
    // add one to the location means move to the next location
    // if the next location is empty, it will be wrong
    // else x will be the value of the next location
    scanf("%d",p1);// or scanf("%d",&x);
    //p2 = &x;// incorrect
    printf("%x\n",p1);// the location of x
    printf("%x\n",&p1);// the location of pointer
    printf("%d\n",*p1);// take out the value in p1(x)
    int a[5] = {1,2,3,4,5};
    printf("%d %d %d\n", *a ,a[0], *&a[0]);// three ways to output the first element of the array
    int *p;
    p = &a[0];
    for(int i = 0;i<5;i++){// another method to output the array
         printf("%d ",*(p+i));// p+n points to the address p+nk where k is size of the data type
    }
    printf("\n");
    int *p3[5];// each element in the array is a pointer that points to an int data 
    for(int i = 0;i<5;i++){
        printf("%x ",p3[i]);
    }
    char str1[80] = "hello";
    char str2[80];
    char *pa,*pb;
    puts(str1);
    pa = str1;// initialize the pointer
    puts(pa);
    printf("\n");
    pb = str2;
    while(*pa != '\0'){// copy str1 to str2
        *pb = *pa;// copy
        pa++;// move to next location
        pb++;// move to next location 
    }
    puts(pb);
    puts(str2);
    /*What the difference between char str[10] and char *ps? 
      str must give it characters because it is a constant variable and is fixed in a specific address
      we can't use str2 = str1;
      but *ps is not a constant variable and can be assigned to any value*/
    typedef struct{
        char name;
        int age;
    }person;
    person jimmy;
    person *pp;
    pp = &jimmy;
    pp -> age = 30;// equivalent to jimmy.age
    //strcpy(pp -> name,"Enns");
    char A = 'y';
    char B = 'n';
    swap(&A,&B);
    printf("%c %c",A,B);
    return 0;
}