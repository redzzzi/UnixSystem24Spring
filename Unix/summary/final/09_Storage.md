# Storage Classes in C
- C
    - ***Low-level*** language that allows us to exploit underlying features of the architecture
    - 오류가 발생하기 쉬움
    - 절차 지향적 (not object-oriented)
    - "weakly-typed" or "type-unsafe"
- Generic C Program Layout
```c
#include <system_files>
#include "local_files"

#define macro_name macro_expr

/* declare functions */
/* declare external variables & structs */

int main(int argc, char* argv[]) {
    /* the innards */
}

/* define other functions */
```

## C Syntax: main
- `main`에서 command-line args 입력을 받으려면?
```c
int main(int argc, char* argv[])
```
```c
int main(int argc, char** argv)
```
- 각 인자의 의미
    - `argc`
        - command line의 문자열 개수
        - 실행 프로그램 명령어부터 하나로 카운트하고, 각 인자를 카운트
    - `argv`
        - command-line args의 문자열을 담고 있는 포인터 배열
        - 마지막 인자 뒤에 `NULL` 포인터가 들어있음

## Primitive Types in C
| **C Data Type** | **32-bit** | **64-bit** | **printf** |
| :---: | :---: | :---: | :---: |
| **char** | 1 | 1 | `%c` |
| short int | 2 | 2 | `%hd` |
| unsigned short int | 2 | 2 | `%hu` |
| **int** | 4 | 4 | `%d`/`%i` |
| unsigned int | 4 | 4 | `%u` |
| long int | 4 | 8 | `%ld` |
| long long int | 8 | 8 | `%lld` |
| **float** | 4 | 4 | `%f` |
| **double** | 8 | 8 | `%lf` |
| long double | 12 | 16 | `%Lf` |
| **pointer** | 4 | 8 | `%p` |

## Basic Data Structures
- C는 객체를 지원하지 않는다. (절차지향이라 그런가..?)
### Arrays
- 연속적인 메모리 청크
- 배열은 메소드가 없으면, 걔네는 자기 길이를 모른다.
- 배열 끝이 넘치는 게 쉬운 일이라 보안상 버그가 일어날 수 있다.
### Strings
- null로 끝나는 문자 배열이다.
- 문자열은 메소드가 없지만 `string.h`를 활용할 수 있다.
- 선언된 문자열을 ***string literal***이라고 한다.
### Structs
- 가장 객체같은 특징지만, 사실 field의 모음이다.

## Function Ordering
- 선언되지 않은 함수는 *부르면 안된다.*
- Solution
    1. 순서를 뒤집는다.
        - who-calls-what 순서가 명확해야 한다.
    2. 함수 선언
        - 컴파일러에 **인자**와 **리턴 타입**을 먼저 알려주는 function prototype을 선언한다.

## Function (Declaration VS. Definition)
- ***Declaration***: description of a thing
    - e.g. function prototype, external variable declaration
        - Often in header files and incorporated via #include
        - Should also #include declaration in the file with the actual definition to check for consistency
    - Needs to appear in **all files** that use that thing
- ***Definition***: the thing itself
    - e.g. code for function, var def that creates storage
    - 중복없이 **definition은 한 번만** 이루어져야 한다.

# Visibility of Symbols: `extern`, `static`
- namespace
    - 전역 변수로 정의했던 변수는 *external linkage*의 활용으로 외부 파일에서 사용할 수 있다.
        - The variable is *defined* in one file and *declared* in the other(s)
        - symbol은 하나의 위치에서 해결된다.
    - *internal linkage*를 사용하면 외부 파일에서 사용할 수 없다.
        - 각 파일에서 *define*되어야 한다.
        - 두 프로그램이 link되면, symbol은 두 개의 위치로 해결된다.
## External Linkage
- `extern` makes a *declaration* of something externally-visible

## Internal Linkage
- `static`(in the global context) restricts a definition to visibility within that file
    - 앞에 static 키워드를 붙여줌으로써 internal linkage를 강제한다.

## Linkage Issues
- every global (vars and funcs) is `extern` by default
    - `static` specifier를 붙이지 않으면, 다른 모듈이 같은 이름 가지고 있을 때 collision이 일어날거임!!
        - 그나마 나은 시나리오: 컴파일러 또는 링커 에러
        - 아주 그냥 망한 시나리오: 정의되고 선언된거 다 뭉갬
- 아래 것들을 습관 들이자!
    - Use `static` to "defend" your globals
    - Place external declarations in a module's header file

## Static Confusion
- `static`을 아까 global context에서 봤지만, 일관된 local variable로 사용할 수도 있다.
    - 해당 방식으로 선언된 변수는, 프로그램이 돌아갈 때 저장공간이 `.data` 또는 `.bss` segment에 할당된다.
    - 한 번 초기화 되면, 함수에서 사용됐을 때 값을 유지한다.

### static variables
```c
static int i;

void f(void) {
    static int j;
}
```
- block **바깥**에서 사용된 static: 변수가 선언된 파일 내에서만 visible
- block **안**에서 사용된 static: block 지속 시간동안 기능을 하며, 한 번만 초기화된다.

### extern variables
- extern으로 변수 쓴다고 해서, 메모리 공간을 또 할당하지는 않음
- e.g. `stdin`, `stdout`, `stderr` 각각 standard input, standard output, standard error streams를 가리킨다.
- extern vars는 주로 헤더 파일에 선언된다.
- external variable의 초기화는 .c 파일의 정의에서 이루어진다.

## typedef
- `typedef`를 활용하여 새로운 타입을 정의할 수 있다.
```c
typedef unsigned int size_t;
```

## Header files
- C 프로그램을 여러 개의 파일로 나누려면, 헤더 파일에 function과 type 선언을 해줘야 한다.

### Good!
- `list.h`
```c
struct node {
    int value;
    struct node *next;
};

typedef struct node List;
extern List *head;

int isEmpty();
void add(int);
void remove(int);
```
- `main.c`
```c
#include "list.h"

int main() {
    add(10);
    isEmpty();
    head = NULL;
}
```
- `list.c`
```c
#include "list.h"

List *head = NULL;

int isEmpty() {...}
void add(int v) {...}
void remove(int v) {...}
```

# Example
- `stlocal.c`
```c
#include <stdio.h>

void find_PW();
void find_ID();

int main() {
    int service;                         // a variable for storing user's request
    do {
        printf("\n[1] ID Search    [2] PW    [3] Exit\n");
        printf("Please enter your service number [1] ~ [3]");
        scanf("%d", &service);

        switch (service) {
            case 1: find_ID(); break;    // invoke find_ID
            case 2: find_PW();;          // invoke find_PW
        }
    } while (service != 3);
    return 0;
}

void find_ID() {
    static int count_ID = 0;             // storing the number of ID search
    count_ID++;
    printf("\nYou called find_ID() %d time(s).\n"), count_ID);
}

void find_PW() {
    int count_PW = 0;                    // local variable
    count_pw++;
    printf("\nYou called find_PW() %d time(s).\n"), count_PW);
}
```
- `stglobal.c`
```c
#include <stdio.h>

void find_PW(); void find_ID();

char title[10] = "NowQuiz";
static int count_service = 0;

int main() {
    int service;
    do {
        printf("\n[1] ID Search    [2] PW    [3] Exit\n");
        printf("Please enter your service number [1] ~ [3]");
        scanf("%d", &service);

        switch (service) {
            case 1: find_ID(); break;    // invoke find_ID
            case 2: find_PW();;          // invoke find_PW
        }
    } while (service != 3);
    return 0;
    }
}

void find_ID() {
    static int count_ID=0; // static local variable
    count_ID++; // increase count_ID by 1
    count_service++; // increase total counter by
    printf("\n Your are visiting the %s game.\n",title);
    printf("\n Total number of requests: %d,the number of requests for ID_search: %d.\n",
    count_service, count_ID);
}

void find_PW() {
    static int count_PW=0; // static local variable
    count_PW++; // increase count_PW by 1
    count_service++; // increase total counter by
    printf("\n Your are visiting the %s game.\n",title);
    printf("\n Total number of requests: %d,the number of requests for PW_search: %d.\n",
    count_service, count_PW);
}
```
