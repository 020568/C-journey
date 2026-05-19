#include <stdio.h>
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    char str[n];
    scanf("%s",str);

    for(int i=0;i<t;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(str[j]=='B' && str[j+1]=='G')
            {
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
                j++;
            }
        }
    }
    
    printf("%s",str);
    return 0;

}