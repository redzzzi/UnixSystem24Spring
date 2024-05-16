#include <stdio.h>

void find_PW();
void find_ID();

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
	printf("\n You called find_ID() %d time(s).\n", count_ID);
}

void find_PW() {
		int count_PW = 0;
		count_PW++;
		printf("\n You called find_PW() %d time(s)...\n", count_PW);
}
