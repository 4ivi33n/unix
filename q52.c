#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	pid_t pid;
	int i;
	for (i=0;;i++) {
		pid = fork();
		if (pid > 0) {
			printf("zombie born %d",i+1);
			sleep(1);
		} else {
			exit(0);
		}
	}
	sleep(100);
	return 0;
}
