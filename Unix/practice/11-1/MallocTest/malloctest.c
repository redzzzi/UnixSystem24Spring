#include <stdio.h>
#include <stdlib.h>

int main() {
  int* p;  // pointer to the dynamically allocated blockes
  int n, i;
  printf("The number of your inputs:> ");
  scanf("%d", &n);
  if (n <= 0) { // checking the number
    printf("Error: Wrong numbers.\n");
    printf("Program ended...\n");
    return -1;
  }
  p = (int*)malloc(n*sizeof(int));
  if (p == NULL) {
    printf("Error: Not enough memory.\n");
    printf("Program ended...\n");
    return -1;
  }
  for (i = 0; i < n; ++i)
    scanf("%d", &p[i]);
  printf("Printing the numbers in reverse order.\n");

  for (i = n-1; i >= 0; --i)
    printf("%d\t", p[i]);
  printf("\n");
}
