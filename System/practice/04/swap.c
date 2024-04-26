#include <stdio.h>

void swap(long *xp, long *yp) {
  int t0 = *xp;
  int t1 = *yp;
  *xp = t1;
  *yp = t0;
}

int main() {
  long a = 123;
  long b = 456;
  swap(&a, &b);

  printf("a = %ld\nb = %ld\n", a, b);
  return 0;
}
