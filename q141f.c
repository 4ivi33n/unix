#include <stdio.h>
#include <unistd.h>
int main() {
	char line[100];
	int n,a,b;
	while ((n = read(STDIN_FILENO,line,100)) > 0) {
		line[n] = 0;
		if (sscanf(line,"%d%d", &a,&b) == 2) {
			sprintf(line, "%d\n",a+b);
			if(write(STDOUT_FILENO,line,n) != n) {}

		}
	}
	return 0;
}
