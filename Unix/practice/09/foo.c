#include <stdio.h>

// A global variable, defined and
// initialized here in foo.c.
// It has external linkage by
// default.

int counter = 1;

void bar();

int main(int argc, char** argv) {
	printf("%d\n", counter);
	bar();
	printf("%d\n", counter);
	return 0;
}
