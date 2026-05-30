#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
main()
{
    char str1[50];
    char str2[50];
    gets(str1);
    gets(str2);
    int cmp=strcmp(str1,str2);
    if(cmp<0) printf("str1<str2");
    else if(cmp==0) printf("str1=str2");
    else printf("str1>str2");
    return 0;
}