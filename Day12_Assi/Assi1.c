//1.The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client process print the result.

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
 //cliet
 
int main()
{ 
   int num1,num2,ret,fd,fd1,res,cnt;
   
   

     fd = open("/home/akshada/Desktop/EOS_Assignment/Day12_Assi_fifo",O_WRONLY);
     if(fd < 0) 
     {
	perror("open() failed");
	_exit(1);
     }

   printf("Enter two numbers : ");
   scanf("%d %d", &num1,&num2);
    
   cnt = write(fd, &num1, sizeof(num1));
   cnt = write(fd, &num2, sizeof(num2));

    fd1 = open("/home/akshada/Desktop/EOS_Assignment/Day12_Assi_fifo2",O_RDONLY);
   if(fd < 0)
   {
	perror("open() failed");
	_exit(1);
   }
   cnt = read(fd1, &res, sizeof(res));
   printf("Addition= %d\n",res);

   
 return 0;
  close(fd);
  close(fd1);
 }
