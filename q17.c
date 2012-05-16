#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main() {
	//ps-axj;
	pid_t p = fork();
	if (p < 0) perror("fork  failure");
	if (p > 0) {printf("child process id = %d", p); exit(0);}
	umask(0);
	setsid();
	chdir("/");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	sleep(100);
	return 0;
}
