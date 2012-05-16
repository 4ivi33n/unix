#include <stdio.h>
int main() {
	char a[100],b[100];
	while(scanf("%s%s",a,b) != EOF) {
		printf("%s%s\n",a,b); 
		fflush(stdout);
	}
	return 0;
}
