#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
jmp_buf buf;
void func2() {
	printf("func2");
	longjmp(buf,1);
}
void func() {
	printf("func");
	func2();
}
int main() {
	if (setjmp(buf) != 0) {
		printf("after longjmp");
		return 0;
	}
	func();
	printf("main");
	return 0;
}

