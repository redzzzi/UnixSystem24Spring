#include <stdio.h>

void find_PW();
void find_ID();

char title[10] = "NowQuiz";
static int count_service = 0;

int main() {
	int service; // a variable for storing user's request
	do {
    printf("<<<1. ID Search 2. PW search 3. Exit >>>\n");
    printf("Please enter your service number (1-3)> ");
    scanf("%d", &service);

    switch(service) {
      case 1: find_ID(); break;
      case 2: find_PW();
    }
  } while (service != 3);

  return 0;
}

void find_ID() {
	static int count_ID = 0;
	count_ID++;
  count_service++;

	printf("\n You are visiting the %s game.\n", title);
  printf("\n Total number of requests: %d, the number of requests for ID_search: %d.\n", count_service, count_ID);
}

void find_PW() {
  static int count_PW = 0;
  count_PW++;
  count_service++;

  printf("\n You are visiting the %s game.\n", title);
  printf("\n Total number of requests: %d, the number of requests for PW_search: %d.\n", count_service, count_PW);
}
