#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    double money[n+1];
    double alarm[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&money[i]);
        alarm[i]=0.0;
    }

    double total_stolen=0.0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        double z;
        scanf("%d %d %lf",&x,&y,&z);
        if(money[x]<z)
        {
            break;
        }

        else if(money[x]>=z)
        {
            double cur_stolen=z-(int)z;
            total_stolen+=cur_stolen;
            money[x]-=z;
            money[y]+=z-cur_stolen;
            alarm[y]+=cur_stolen;
        }

        if(alarm[y]>1.0)
        {
            break;
        }
    }

    printf("%.2lf",total_stolen);
}