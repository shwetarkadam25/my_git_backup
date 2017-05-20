#include<stdio.h>
#include<stdlib.h>
#define one 0
int main(){

printf("HELLO Newbie \n");
printf("DONT LOSE HOPE AND JUST KEEP GOING");

printf("\nTrying out new stuff in c\t");

#ifdef  one
printf("one is defined");

#endif

#ifndef one
printf("one is not defined");
#endif


return 0;}
