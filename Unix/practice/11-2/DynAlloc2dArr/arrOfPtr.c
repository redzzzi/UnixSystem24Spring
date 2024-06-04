#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 3

void init2DArrayRandom(int **arr, int rows, int cols) {
  int i, j;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      arr[i][j] = rand()%10;
    }
  }
}

void print2DArray(int **arr, int rows, int cols) {
  int i, j;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      printf("[%d, %d]: %d\t", i, j, arr[i][j]);
    }
    printf("\n");
  }
}

int main() {

}
