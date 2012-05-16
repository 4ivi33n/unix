#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main() {
	pid_t p;
	if ((p = fork()) < 0) {

	} else if (p == 0) {
		if (execl("/home/ameen/Desktop/unix2/inter","inter", "arg1","arg2",(char*)0) < 0) {

		}
	}
	if (waitpid(p,NULL,0)< 0) {

	}

	return 0;
}
