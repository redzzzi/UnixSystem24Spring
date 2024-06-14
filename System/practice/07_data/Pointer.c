#include <stdio.h>

int main() {
  int A1[3] = {0, 1, 2};
  printf("|---Understanding Pointers & Arrays #1---|\n\n");
  // int A1[3];
  printf("int A1[3] = {0, 1, 2};\n");
  printf("A1 : %p\n", A1);
  printf("*A1 : %d\n", *A1);
  printf("\n");  
  int *A2;
  printf("int *A2;\n");
  printf("A2 : %p\n", A2);
  printf("*A2 : %d\n", *A2);

  printf("\n|---Understanding Pointers & Arrays #2---|\n\n");
  // printf("int A1[3];\n");
  printf("int A1[3] = {0, 1, 2};\n");
  printf("A1 : %p\n", A1);
  printf("*A1 : %d\n", *A1);
  printf("\n");  
  // printf("**A1 : %d\n", **A1);
  int *A3[3] = {&A1[0], &A1[1], &A1[2]};
  printf("int *A3[3] = {&A1[0], &A1[1], &A1[2]};\n");
  printf("A3 : %p\n", A3);
  printf("*A3 : %p\n", *A3);
  printf("**A3 : %d\n", **A3);
  printf("\n");  
  int (*A4)[3] = &A1;
  // int (*A4)[3];
  printf("int (*A4)[3] = &A1;\n");
  printf("A4 : %p\n", A4);
  printf("*A4 : %p\n", *A4);
  printf("**A4 : %d\n", **A4);

  return 0;
}
