#include <unistd.h>
#include <stdio.h>
int main() {
	int fd[2];
	int p;
	if (pipe(fd)<0) {

	} 
	if ((p = fork()) < 0) {

	} else if (p>0) {
		close(fd[0]);
		write(fd[1],"hi\n",4);

	} else {
		close(fd[1]);
		char line[100];
		int n = read(fd[0],line,100);
		write(STDOUT_FILENO,line,n);

	}
	return 0;
}
