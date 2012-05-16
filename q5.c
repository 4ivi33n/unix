#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
	pid_t p;
	p = fork();
	if (p == 0) {
		printf ("child = %d", getpid());
		exit(0);
	} else {
		printf ("parent = %d, child = %d", getpid(), p);
		sleep(20);
	}
	if (waitpid(p,NULL,0)  != p) 
		printf("wait error");
	exit(0);
}
