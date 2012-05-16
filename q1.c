#include <stdlib.h>
#include <stdio.h>
void exit1() { printf ("exit1"); }
void exit2() { printf("exit2"); }
int main() {
	if (atexit(exit1) != 0) printf("error");
	if (atexit(exit2) != 0) printf("error2");
	printf("main");
	return 0;
}

