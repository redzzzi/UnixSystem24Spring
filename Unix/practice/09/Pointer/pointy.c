#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
  int x = 351;
  int* p;

  p = &x;
  printf("&x is %p\n", &x);
  printf(" p is %p\n", p);
  printf(" x is %d\n", x);

  *p = 333;
  printf(" x is %d\n", x);

  return 0;
}
