#include <stdio.h>

long absdiff_j(long x, long y) {
  long result;
  int ntest = x <= y;
  if (ntest) goto Else;
  result = x - y;
  goto Done;
Else:
  result = y - x;
Done:
  return result;
}

int main() {
  printf("the result: %ld\n", absdiff_j(5, 10));
  return 0;
}
