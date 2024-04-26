#include <stdio.h>

int main() {
  int x = 10;
  // int *ptr;    // 정수형 포인터 변수 ptr을 선언
  // ptr = &x;    // ptr에 변수 x의 주소를 할당
  int *ptr = &x; // 위 두 코드와 이 한 코드는 같은 역할을 한다.

  printf("x의 값: %d\n", x);     // x의 값 출력
  printf("x의 주소: %p\n", &x);  // x의 메모리 주소 출력
  printf("ptr이 가리키는 값: %d\n", *ptr);  // ptr이 가리키는 값 출력
  printf("ptr의 값: %p\n", ptr);           // ptr의 값 출력
  return 0;
}
