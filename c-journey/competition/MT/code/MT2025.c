#include <stdio.h>
int main()
{
    int a;
    int m;
    scanf("%d %d",&a,&m);

    int r=a%m;
    int cnt;
    while(r!=0)
    {
        r=(2*r)%m;
        cnt++;
        if(cnt>m)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;

}