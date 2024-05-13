#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int ret,s,i,j;
   i=1;
   while(1)
  {
     ret = fork();
     if(ret == 0)
     {  
         //child task
         printf("child task if count : %d",i);
         _exit(0);
     }
     else if (ret==-1)//fork failed
     break;
   
     else
     {
      i++;
      printf("else count : %d\n",i);
     }
  }
  for (j=1;j<=i;j++)
     wait(&s);
  }

