#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

enum{Add=1, Minus, Multi, Divide};

int main(int argc, char** argv) {
	double val1, val2;
	int select;
	double result;
	val1 = atof(argv[1]);
	val2 = atof(argv[2]);
	select = atoi(argv[3]);
	switch(select) {
		case Add:
			result = Addfunc(val1, val2);
			break;
		case Minus:
			result = Minusfunc(val1, val2);
			break;
		case Multi:
			result = Multifunc(val1, val2);
			break;
		case Divide:
			result = Dividefunc(val1, val2);
			break;
		default:
			printf("Repeat the other value");
			break;
	}
	printf("Result value: %lf\n", result);
}

