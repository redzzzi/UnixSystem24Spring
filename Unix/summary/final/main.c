#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int c;

  fp = fopen(argv[1], "w");
  c = fgetc(stdin);
  while (c!=EOF) {
    putc(c, fp);
    c = fgetc(stdin);
  }
  printf("A write operation to %s is completed.\n", argv[1]);
}
