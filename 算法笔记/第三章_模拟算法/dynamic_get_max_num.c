#include <stdio.h>
int school[1000100];

int main()
{
    int score,N;
    scanf("%d",&N);
    int id;
    
    int max_id=0;
    int max_score=-1;
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&id,&score);
        school[id]+=score;

        if(school[id]>max_score)
        {
            max_score=school[id];
            max_id=id;
        }
    }

    printf("%d %d\n",max_id,max_score);
    return 0;
}