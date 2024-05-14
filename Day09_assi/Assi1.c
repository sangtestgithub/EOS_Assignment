//1. Input signal number and a process id from user. Send given signal to the given process using kill() syscall.



#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>



int main()
{
   int signo, proid;
   printf("Enter signal number : ");
   scanf("%d", &signo);
   printf("Enter process id : ");
   scanf("%d", &proid);

   int ret = kill(proid,signo);
   if(ret == 0)
   {
	   printf("killed....\n");
   }
   else
   {
       printf("not killed...\n");
   }
   return 0;
}
