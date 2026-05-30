#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student 
{
    int score;
    char id[15];
    int local_rank;
    int location_number;
}stu[30010];

bool cmp(student a,student b)
{
    if(a.score != b.score)
    {
        return a.score>b.score;
    }

    else
    {
        return (strcmp(a.id,b.id))<0;
    }
    
}

int main()
{
    int n,k,num=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%s %d",stu[j].id,stu[j].score);
            stu[j].location_number=i+1;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].local_rank=1;
        for(int j=num-k;j<num;j++)
        {
            if(stu[j].score==stu[j-1].score)
            {
                stu[j].local_rank=stu[j-1].local_rank;
            }
            else
            {
                stu[j].local_rank=j+1-(num-k);
            }
        }
    }

    printf("%d\n",num);
    sort(stu,stu+num,cmp);
    int r=1;
    for(int i=0;i<num;i++)
    {
        if(i>0 && stu[i].score != stu[i-1].score)
        {
            r=i+1;
        }
        printf("%s",stu[i].id);
        printf("%d %d %d\n",r,stu[i].local_rank,stu[i].local_rank);
    }
}