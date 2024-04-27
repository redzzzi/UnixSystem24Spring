#include <stdio.h>

long absdiff_j(long x, long y) {
  long result;
  int ntest = x <= y;
  if (ntest) goto Else;
  result = x - y;
  goto Done;
Else:
  result = y - x;
  printf("Else) the result: %ld\n", result);
Done:
  printf("Done1) the result: %ld\n", result);
  return result;
  printf("Done2) the result: %ld\n", result);
}

int main() {
  printf("main) the result: %ld\n", absdiff_j(5, 10));
  return 0;
}
