#include <stdio.h>
int main() {
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF) {
		printf("%d\n",a+b); 
		fflush(stdout);
	}
	return 0;
}
