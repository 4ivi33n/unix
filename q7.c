#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
	pid_t pid;
	if ((pid = fork()) < 0) {
		printf("fork error");
	} else if (pid == 0) {
		if ((pid = fork()) < 0) 
			printf("error");
		if (pid > 0) {
			exit(0);
		} else {
			sleep(2);
			printf("second child, parent pid = %d\n",getppid());
			exit(0);
		}
	}
	if (waitpid(pid,NULL,0) != pid)
		printf("wait error");
	exit(0);
}
