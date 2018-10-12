#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int status;
    pid_t pc,pr;
    if ((pc = fork()) < 0)
    {
        printf("error in fork!");
        exit(1);    /*fork�����˳�*/
    }
    else if(pc==0)
	{  /*�ӽ���*/
        printf("This is child process with pid of %d.\n",getpid());
        exit(-2);  /*�ӽ��̷���3 */
    }
    else
	{   /*������*/
        pr=wait(&status);
        if(WIFEXITED(status))
		{   /*���WIFEXITED���ط���ֵ*/
            printf("the child process %d exit normally.\n",pr);
            printf("the return code is %d.\n",WEXITSTATUS(status));
        }
        else
		{   /*���WIFEXITED������ */
            printf("the child process %d exit abnormally.\n",pr);
		}
    }
    return 0;
}
