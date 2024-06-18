#include <stdio.h>

int sumAll(int a[5]);

int main(int argc, char** argv) {
  int numbers[] = {1, 2, 3, 4, 5};
  int sum = sumAll(numbers);
  printf("sum is: %d\n", sum);
  return 0;
}

int sumAll(int a[5]) {
  int i, sum = 0;
  for ( i=0; i<5; i++) {
    sum += a[i];
  }
  return sum;
}
