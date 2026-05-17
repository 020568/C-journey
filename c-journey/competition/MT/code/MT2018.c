#include <stdio.h>
#define MOD 1000000007
int main()
{
    char s[100005];
    scanf("%s",s);

    long long ans=0;
    long long cur=0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='0')
        {
            cur=0;
        }
        else
        {
            cur++;
        }
        ans=(cur+ans)%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}

