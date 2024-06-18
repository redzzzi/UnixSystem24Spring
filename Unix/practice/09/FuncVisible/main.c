#include <stdio.h>
extern int bar(int x);
int main(int argc, char** argv) {
printf("%d\n", bar(5));
return 0;
}
