#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
	int n, fd1[2], fd2[2], pid;
	char line[100];
	if (pipe(fd1) < 0 || pipe(fd2) < 0) {}
	if ((pid = fork()) < 0) {}
	else if (pid > 0) {
		close(fd1[0]);
		close(fd2[1]);
		while (fgets(line,100,stdin) != NULL) {
			if (write(fd1[1],line, strlen(line)) != strlen(line)) {}
			if ((n=read(fd2[0],line,100))<0) {}
			if (n == 0) printf("pipe closed");
			if (fputs(line,stdout) == EOF) printf("error");
		}
		exit(0);
	} else {
		close(fd1[1]);
		close(fd2[0]);
		dup2(fd1[0],STDIN_FILENO);
		dup2(fd2[1],STDOUT_FILENO);
		execl("./q141f","q141f",(char*)0);
		exit(0);
	}

	return 0;
}
