#include <stdio.h>

int hashFunc(char str[],int len)
{
    int id=0;
    for(int i=0;i<len;i++)
    {
        id=id*26+(str[i]-'A');
    }
    return id;
}