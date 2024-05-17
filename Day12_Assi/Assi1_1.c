#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

//server

int main()
{
   int n1,n2,ret,fd,fd1,res,cnt;
   fd = open("/home/akshada/Desktop/EOS_Assignment/Day12_Assi_fifo",O_RDONLY);
   if(fd1 < 0)
   {
    perror("open() failed");
    _exit(1);
   }

   printf("waiting for data....\n");
    
   cnt = read(fd, &n1, sizeof(n1));
   cnt = read(fd, &n2, sizeof(n2));

   printf(".......numbers received....\n");

   res = n1 +n2;
  
    fd1 = open("/home/akshada/Desktop/EOS_Assignment/Day12_Assi_fifo2",O_WRONLY);
    if(fd1 < 0)
    {
		perror("open() failed");
		_exit(1);
     }


     cnt = write(fd1, &res, sizeof(res));
 //  printf("resut : %d\n",r);
   close(fd);
   close(fd1);
   return 0;
}
