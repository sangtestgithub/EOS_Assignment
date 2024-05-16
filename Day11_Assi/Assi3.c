//3. Find the size of pipe buﬀer in your system.


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
 
int arr[30];

void sigint_handler(int sig)
{
   close(arr[1]);
   close(arr[0]);
   _exit(0);
}


int main()
{
    char ch = 'A';
    int ret, count = 0;
    ret = pipe(arr);

     struct sigaction sa;
     memset(&sa, 0, sizeof(struct sigaction));
     sa.sa_handler = sigint_handler;
     ret = sigaction(SIGINT, &sa, NULL);
     if(ret < 0) 
     {
	perror("sigaction() failed");
	_exit(1);

    }
    while(1)
    {
	    write(arr[1], &ch, 1);
	    count++;
	    printf("bytes written : %d\n", count);
    }
    return 0;

}
