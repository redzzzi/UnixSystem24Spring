#include <stdio.h>

int main() {
  size_t i;
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8}; // 추가

  // int cnt = 5;
  int cnt = -5; // cnt is signed and < 0
  for (i = cnt-2; i < cnt; i--) {
    a[i] += a[i+1];
  }
  printf("%d\n", a[0]);
  return 0;
}
