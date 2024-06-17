#include <stdio.h>
#include <string.h>
int calc(float newcost) {
  int result;
  result = newcost * 5;
  return result;
}
int main(void) {
  float cost;
  char name[10];
  int count, count2;
  char *nameptr;
  int *countptr = & count2;
  cost = 2.00;
  count = calc(cost);
  *countptr = count;
  strcpy(name, "Richard");
  nameptr = "petersen";
  return 0;
}
