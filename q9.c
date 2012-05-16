#include <unistd.h>
#include <stdio.h>
int main() {
	int fd[2];
	if (pipe(fd)<0) printf("error");
	write(fd[1], "abc",4);
	char line[100];
	read(fd[0],line,4);
	printf("%s",line);
	return 0;
}
