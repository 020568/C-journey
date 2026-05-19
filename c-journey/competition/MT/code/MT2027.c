#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int cnt;
    for(int i=0;n!=0;i++)
    {
        if(n%2==0)
        {
            n/=2;
        }
        else if(n%2!=0)
        {
            n-=1;
        }
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}