#include <stdio.h>
#include <string.h>
#include <assert.h>  // assert() is defined

void copy(char *dest, char *src) {
  assert(dest != NULL);   // if dest == NULL, then abort
  assert(src != NULL);    // if src == NULL, then abort
  strcpy(dest, src);      // copy string
}

int main() {
  char s1[100];
  char *s2 = "Hello, world!";

  copy(s1, s2);    // normal execution
  copy(NULL, s2);  // src is NULL
  // Assertion failed: dest != NULL
  return 0;
}
