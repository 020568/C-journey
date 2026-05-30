#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val,x,y;
}Node;

Node nodes[100005];
int xs[100005];
int ys[100005];

int cmp_int(const void* a,const void* b)
{
    return *((int*)a)-*((int*)b);
}

int cmp_val(const void*a,const void* b)
{
    return ((Node*)a)->val-((Node*)b)->val;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int N=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&nodes[N].val);
            nodes[N].x=i;
            nodes[N].y=j;
            N++;
        }
    }
    qsort(nodes,N,sizeof(Node),cmp_val);
    long long ans=0;

    int i=0;
    while(i<N)
    {
        int j=i;
        while(j<N && nodes[i].val==nodes[j].val)
        {
            j++;
        }
        int k=j-i;
        for(int t=0;t<k;t++)
        {
            xs[t]=nodes[i+t].x;
        }
        qsort(xs,k,sizeof(int),cmp_int);

        long long pre=0;
        for(int t=0;t<k;t++)
        {
            ans+=(long long)xs[t]*t-pre;
            pre+=xs[t];
        }

        pre=0;
        for(int t=0;t<k;t++)
        {
            ys[t]=nodes[i+t].y;
        }
        qsort(ys,k,sizeof(int),cmp_int);
        for(int t=0;t<k;t++)
        {
            ans+=(long long )ys[t]*t-pre;
            pre+=ys[t];
        }

        i=j;
    }
    printf("%lld\n",ans);
    return 0;


}