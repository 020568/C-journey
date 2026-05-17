#include <stdio.h>
int main()
{
    int len;
    scanf("%d",&len);
    char s[105];
    scanf("%s",s);

    int cnt[26][26]={0};
    int max_cnt=-1;
    char res[3]="";
    for(int i=0;i<len-1;i++)
    {
        cnt[s[i]-'A'][s[i+1]-'A']++;
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(cnt[i][j]>max_cnt)
            {
                max_cnt=cnt[i][j];
                res[0]='A'+i;
                res[1]='A'+j;
                res[2]='\0';
            }
        }
    }
    printf("%s",res);
    return 0;
}