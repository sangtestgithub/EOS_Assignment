#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {

	int ret ,err,s, fd;
	printf("parent started !!");
	ret =fork();
	if(ret ==0) {
		//input redirection
		fd = open("in.txt", O_RDONLY,0644);
		dup2(fd,0);
		close(fd);
		
		err = execlp("wc", "wc", "in.txt",NULL);
		if(err < 0) {
			perror("exec() failed");
			_exit(1);
			}
		}
		else 
			waitpid(-1,&s,0);
			printf("parent completed!!");
			return 0;
}
