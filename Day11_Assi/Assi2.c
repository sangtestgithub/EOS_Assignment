//2. The child process send two numbers to the parent process via pipe. The parent process calculate the sum and return via another pipe. The child process print the result and exit. The parent process wait for completion of the child and then exit.


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int ret, arr1[30], arr2[30], res, num1, num2, n1, n2, r, s;
    ret = pipe(arr1);
    ret = pipe(arr2);
    ret = fork();
    if(ret == 0)
    {
       close(arr1[0]);
       close(arr2[1]);
       printf("Enter two numbers : \n");
       scanf("%d %d",&num1,&num2);
       write(arr1[1], &num1, sizeof(num1));
       write(arr1[1], &num2, sizeof(num2));


       read(arr2[0], &res, sizeof(res));
       printf("result : %d\n", res);
       printf("child: data written in pipe: %d bytes\n", res);
       close(arr2[0]);
       close(arr1[1]);
    }
    else
    {
       close(arr1[1]);
       close(arr2[0]);

       read(arr1[0], &n1, sizeof(n1));
       read(arr1[0], &n2, sizeof(n2));

       r = n1 + n2;

       write(arr2[1], &r, sizeof(r));
       printf("parent: data read from pipe: %d bytes \n", r);
       close(arr2[1]);
       close(arr1[0]);
       waitpid(-1, &s, 0);
    }
    return 0;
}
