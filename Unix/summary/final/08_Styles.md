# Header Guards
## C Preprocessor trick
1. 헤더 파일이 중복 정의되는 것을 보완할 수 있는 방법을 알아보자.
    - conditional compilation(`#ifndef`와 `#endif`)과 함께 macro definition(`#define`)을 사용한다.
2. magic constant로 어지러워진 코드를 정리하는 방법을 알아보자. ex) pi, e
    - macro definition을 사용한다.
## Macros
- pass args to macros
    - 괄호 사용에 주의해야 한다.
```c
#define ODD(x) ((x) % 2 != 0)
```
## Conditional Compilation
- 컴파일 되는 대상을 바꿀 수 있다.
```c
#ifndef TRACE // TRACE가 정의되어 있는 경우 else 이전까지로 compile
#define ENTER(f) printf("Entering %s\n", f);
#define EXIT(f) printf("Exiting %s\n", f);
#else
#define ENTER(f)
#define EXIT(f)
#endif

// print n
void pr(int n) {
    ENTER("PR");
    printf("\n = %d\n", n);
    EXIT("pr");
}
```
