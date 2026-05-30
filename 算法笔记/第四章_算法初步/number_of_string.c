#include <cstdio.h>
const int maxn=100;
char str[maxn][5];
char temp[5];
int hashTable[26*26*26+10]; //number of max storage
int hashFunc(char str[],int len)
{
    int id=0;
    for(int i=0;i<len;i++)
    {
        id=id*26+str[i]-'A';
    }
    return id;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<len;i++)
    {
        scanf("%s",str[i]);
        int id=hashFunc(str[i],3);
        hashTable[id]++;
    }

    for(int i=0;i<m;i++)
    {
        scanf("%s",temp);
        int id=hashFunc(temp,3);
        printf("%d",hashTable[id]);
    }
    return 0;
}