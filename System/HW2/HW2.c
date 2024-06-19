#include <stdio.h>

int main() {
  // 배열 초기화
  int array[5] = {1, 2, 3, 4, 5};

  // A1: 2차원 배열
  int A1[3][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15}
  };

  // A2: 포인터 배열 (각 요소를 array로 초기화)
  int *A2[3][5];
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
       A2[i][j] = &array[j];
    }
  }

  // A3: 2차원 배열을 가리키는 포인터 (A1을 가리킴)
  int (*A3)[3][5] = &A1;

  // A4: 포인터 배열 (각 요소를 array의 각 요소로 초기화)
  int *(A4[3][5]);
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
      A4[i][j] = &array[j];
    }
  }

  // A5: 배열의 포인터 배열 (각 요소를 A1의 행으로 초기화)
  int (*A5[3])[5];
  for (int i=0; i<3; i++) {
    A5[i] = &A1[i];
  }

  // A1 출력
  printf("A1:\n");
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
      printf("%d ", A1[i][j]);
    }
    printf("\n");
  }

  // A2 출력
  printf("\nA2:\n");
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
      printf("%d ", *A2[i][j]);
    }
    printf("\n");
  }

  // A3 출력
  printf("\nA3:\n");
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
      printf("%d ", (*A3)[i][j]);
    }
    printf("\n");
  }

  // A4 출력
  printf("\nA4:\n");
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
      printf("%d ", *A4[i][j]);
    }
    printf("\n");
  }
  
  // A5 출력
  printf("\nA5:\n");
  for (int i=0; i<3; i++) {
    for (int j=0; j<5; j++) {
      printf("%d ", (*A5[i])[j]);
    }
    printf("\n");
  }

  printf("\n학번: 202355597, 이름: 홍지연\n");

  return 0;
}
