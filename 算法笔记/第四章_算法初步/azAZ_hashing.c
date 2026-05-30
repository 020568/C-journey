#include <stdio.h>

int hashFunc(char str[],int len)
{
    int id=0;

    for(int i=0;i<len;i++)
    {
        if(str[i]<='Z' && str[i]>='A')
        {
            id=id*52+str[i]-'A';
        }

        else if(str[i]<='z' && str[i]>='a')
        {
            id=id*52+str[i]-'a';
        }

    }
    return id;
}