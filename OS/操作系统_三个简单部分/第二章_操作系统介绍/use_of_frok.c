#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int
main(int argc,char* argv[])
{
    printf("hello word(pid:%d)\n",(int)getpid());
    int rc=fork();
    if(rc<0) //if fork failed exit
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }

    else if(rc==0) //child new process
    {
        printf("hello,i am child(pid:%d)\n",(int)getpid());
    }

    else
    {
        printf("hello,i am parent of %d(pid:%d)\n",rc,getpid());
    }
    return 0;
}