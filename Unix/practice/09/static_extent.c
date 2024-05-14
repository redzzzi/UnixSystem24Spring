#include <stdio.h>

void foo() {
	static int count = 1;
	printf("foo has been called %d times\n", count++);
}

void bar() {
	int count = 1;
	printf("bar has been called %d times\n", count++);
}

int main(int argc, char** argv) {
	foo(); foo(); bar(); bar(); return 0;
}
