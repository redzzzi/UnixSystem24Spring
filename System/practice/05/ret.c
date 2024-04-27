#include <stdio.h>

int gt(long x, long y) {
  return x > y;
}

int main() {
  printf("3 > 2 --> %d\n", gt(3, 2));
  printf("4 > 2 --> %d\n", gt(4, 2));
  printf("1 > 2 --> %d\n", gt(1, 2));
  return 0;
}
