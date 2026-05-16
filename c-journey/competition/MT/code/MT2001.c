#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,arr;
    int cnt[3]={0,0,0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr);
        cnt[arr%3]++;
    }
        
    int ans=cnt[0]/2;
    ans+=(cnt[1]<cnt[2]?cnt[1]:cnt[2]);
    printf("%d\n",ans);
    return 0;


}