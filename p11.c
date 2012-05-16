#include <stdio.h>
#include <sys/wait.h>
#define max 4096
#define PAGER "${PAGER:-less}"
int main(int argc, char *argv[]) {
	char line[max];
	FILE *in, *out;
	if ((in = fopen(argv[1],"r")) == NULL) 
		printf("can't open file");
	if ((out = popen("less","w")) == NULL) {
		printf("pager error");
	}
	while (fgets(line,max,in) != NULL) {
		if (fputs(line,out) == EOF)
			printf("error");
	}
	if (ferror(in)) printf("fget error");
	if (pclose(out) == -1) printf("error");
	return 0;
}
