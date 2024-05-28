#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int a[2];
  int* b = malloc(2*sizeof(int));
  int* c;

  a[2] = 5;        // assign past the end of an array
  b[0] += 2;       // assume malloc zeros out memory
  c = b + 3;       // mess up your pointer arithmetic
  free(&(a[0]));   // free something not malloc'ed
  free(b);
  free(b);         // double-free the same block
  b[0] = 5;        // use a freed pointer

  // any many more!
  return 0;
}
