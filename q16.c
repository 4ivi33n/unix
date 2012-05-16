#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
static void sig_func(int s) {
	sleep(1);
	while (waitpid(-1,NULL,WNOHANG) > 0) {}
}
int main() {
	struct sigaction s;
	memset(&s,0,sizeof(s));
	s.sa_handler = sig_func;
	if (sigaction(SIGCHLD,&s,0)) {
		perror("FDF");
	}
	int i=0;
	for (i=0;i<50;i++) {
		int p;
		if ((p=fork()) == -1) perror("fork error");
		else if (p == 0) return 0;
	}
	while (sleep(1)) {}
	return 0;
}
