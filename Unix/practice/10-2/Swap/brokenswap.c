#include <stdio.h>

void swap(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char** argv) {
  int a = 42, b = -7;
  printf("before: a = %d, b = %d\n", a, b);
  swap(a, b);
  printf("after: a = %d, b = %d\n", a, b);

  return 0;
}
