#include <unistd.h>
#include <stdio.h>
int main() {
	int i=0;
	pid_t pid;
	char str[] = "hello world\n";

	if (write(STDOUT_FILENO,str,sizeof(str)-1) != sizeof(str)-1) {
		printf("write error");
	}
	printf("before fork\n");
	if ((pid = fork()) < 0) {
		printf("error");
	} else if (pid == 0) {
		i++;
		printf("child process\n");
	} else {
		sleep(1);
		printf("parent process and child id is %d\n",pid);
	}
	printf("%d %d\n", getpid(), i);
	return 0;
}
