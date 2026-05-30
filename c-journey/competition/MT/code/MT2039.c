#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char name[25];
}Toy;

Toy toymap[50005];
int toy_id[50005];
int cup_id[50005];

int cmp_name(const void* a,const void* b)
{
    return strcmp(((Toy*)a)->name,((Toy*)b)->name);
}

int find_binary(char* name,int N)
{
    int low=1;
    int high=N;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int cmp=strcmp(toymap[mid].name,name);
        if(cmp==0) return toymap[mid].id;
        else if(cmp<0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main()
{
    int N,M,T;
    if(scanf("%d %d %d",&N,&M,&T)!=3) return 0;

    for(int i=1;i<=N;i++)
    {
        scanf("%s",toymap[i].name);
        toymap[i].id=i;
        toy_id[i]=i;
        cup_id[i]=i;
    }

    qsort(&toymap[1],N,sizeof(Toy),cmp_name);//从1开始的，如果直接传toymap的话直接报错

    for(int i=0;i<T;i++)
    {
        int p1,p2;//p1,p2是杯子的序号，所以要用toy1和2来代表一下这两个杯子里面的玩具
        scanf("%d %d",&p1,&p2);

        int toy1=cup_id[p1];
        int toy2=cup_id[p2];

        cup_id[p1]=toy2;
        cup_id[p2]=toy1;

        toy_id[toy1]=p2;
        toy_id[toy2]=p1;


    }

    for(int i=0;i<M;i++)
    {
        char query[25];
        scanf("%s",query);

        int id=find_binary(query,N);

        printf("%d\n",toy_id[id]);
    }
}