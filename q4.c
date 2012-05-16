#include <unistd.h>
#include <stdio.h>
int main() {
	int i=0;
	pid_t p;
	printf("before vfork\n");
	if ((p = vfork()) < 0) printf("error");
	else if (p == 0) {
		i++;
		_exit(0);
	}
	printf("pid = %d, i = %d", getpid(), i);
	return 0;
}
