#include <stdio.h>
#include <stdlib.h>

long plus(long x, long y) {
  return x + y;
}

// x와 y를 더한 값을 dest가 가리키고 있는 주소에 저장한다.
void sumstore(long x, long y, long *dest) { // *dest는 메모리값을 가리키는 포인터이다.
  long t = plus(x, y);
  *dest = t;
}

int main(int argc, char *argv[]) {
  long x = atoi(argv[1]);
  long y = atoi(argv[2]);
  long z;
  sumstore(x, y, &z); // &z는 메모리 주소를 의미한다.
  printf("%ld + %ld --> %ld\n", x, y, z);
  return 0;
}
