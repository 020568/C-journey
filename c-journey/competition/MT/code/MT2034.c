#include <stdio.h>
#include <string.h>
int main()
{
    char s[205];
    fgets(s,sizeof(s),stdin);

    int len=strlen(s);
    while(len>0 && (s[len-1]=='\n' || s[len-1]=='\r'))
    {
        s[len-1]='0';
        len--;
    }

    char words[30][205];
    int word_cnt=0;
    char* p=strtok(s," ");
    while(p)
    {
        strcpy(words[word_cnt++],p);
        p=strtok(NULL," ");

    }
    int max_len=0;
    for(int i=0;i<word_cnt;i++)
    {
        int wlen=strlen(words[i]);
        if(wlen>max_len) max_len=wlen;
    }

    for(int j=0;j<max_len;j++)
    {
        char line[205]="";
        int line_len=0;
        for(int i=0;i<word_cnt;i++)
        {
            int wlen=strlen(words[i]);
            if(j<wlen)
            {
                line[line_len++]=words[i][j];
            }
            else
            {
                line[line_len++]=' ';
            }
        }

        while(line_len>0 && line[line_len]==' ')
        {
            line_len--;
        }
        line[line_len]='\0';
        printf("%s\n",line);

    }
    return 0;
}