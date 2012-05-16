#include <stdio.h>
#include <sys/wait.h>
int main() {
	char line[100];
	FILE *in;
	if ((in = popen("/home/ameen/Desktop/unix2/q13f","r")) == NULL) {}
	while (1) {
		fputs("prompt> ", stdout);
		fflush(stdout);
		if (fgets(line,100,in) == NULL) break;
		if (fputs(line,stdout) == EOF) printf("error");
	} 
	if (pclose(in) == -1) printf("close error");
	return 0;
}
