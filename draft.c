#include<stdio.h>

int main()
{
    int a = 0b0101001000100001;
    printf("%x\n", a >> 1);
    printf("%x\n", a >> 2);
    printf("%x\n", a >> 3);
    printf("%x\n", a >> 4);
    printf("%x\n", a >> 5);
    printf("%x\n", a >> 6);
    return 0;
}