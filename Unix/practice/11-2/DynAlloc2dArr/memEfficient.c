#include <stdio.h>
#include <stdlib.h>

void init2D(int *arr, int rows, int cols) {
  int i, j;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      arr[i*cols+j] = 0;
    }
  }
}

int main() {
  int N, M;
  printf("Type N and M orderly.\n");
  scanf("%d %d", &N, &M);
  int *array;
  array = malloc(sizeof(int)*N*M);
  if (array != NULL) {
    init2D(array, N, M);
  }
  // do anything you want to 
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      printf("%d ", array[i*M+N]);
    }
    printf("\n");
  }
}
