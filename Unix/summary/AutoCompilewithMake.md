# make
- 다른 파일과 **종속관계인 파일을 빌딩할 때, 그 절차를 자동화**시켜주는 명령어이다.
- 다양한 업무에 사용이 된다.
    - 보통 프로그램 개발에 쓰인다.
        - 필요할 때만 컴파일러를 돌린다.
        - 필요한 때를 결정하기 위해 **file access time**을 사용한다.

# Building S/W
- 프로그래머는 **build** 과정에 시간을 많이 들인다.
    - build: 소스 코드로부터 프로그램을 만들어나가는 것
- 해당 과정이 반복되면 그 작업을 자동화하고 싶어질 것이다. (아래는 발전 과정이다.)
    1. `Repeating` same tasks
    2. Using `↑` or `history`
    3. Having an `alias` or `shell script`
    4. Having a `Makefile`
## Real Build Process
- 대형 프로젝트인 경우에 다음 특징을 띤다.
    1. `gcc`는 우리가 원래 해오던 방식대로 preprocess, compile, link를 해주지 않는다.
    2. 소스파일이 여러 개라면 그만큼 여러 번의 타이핑을 해야할 것이다.
    3. 소스코드를 배포할 때 빌드하는 로직을 문서화 하고 싶지는 않을 것이다. -> 귀찮자너
    4. 그리고 수정할 때마다 다시 컴파일을 해줘야 하는데, 이것 또한 매우 귀찮은 일이다.
    - 스크립트의 경우 1~3번을 해결해줄 수 있다.

# Recompilation Management
- 불필요한 컴파일을 하지 않는 이론을 ***dependency dag***라고 한다. 
    - **D**irected, **A**cyclic **G**raph
- target *t*를 생성하고자 할 때, **소스**들과 그것들을 직접 또는 간접적으로 사용하는 **명령어**가 필요하다.

# make 명령어 사용해보기
- format
```shell
make -f <makefileName> target
```
```shell
makefile
```
- Default input file
    - *target*을 지정해주지 않으면, 파일에서 첫번째 것을 *target*으로 인식한다.
    pr2부터 예제 따라하기
- Target execution
    - source들 각각을 확인해보아야 한다.
        - `소스가 makefile에서의 target이라면, 재귀적으로 실행한다.`
        - `소스가 존재하지 않는다면, 에러가 난다.`

![image](https://github.com/redzzzi/UnixSystem24spring/assets/127263392/d4bebbdc-c98f-491d-971a-7a7b3ce9c094)

# Rules of `makefile`
```shell
target: dependencies
    command1
    command2
```
- ***target***: 보통 프로그램에 의해 생성된 파일의 이름이다.
- ***dependency***: target을 생성하기 위한 **입력**으로써 사용되는 파일이다.
    - *prerequisite*이라고도 한다. 
- ***system command(s)***: `make`를 수행할 수 있도록 해주는 동작을 의미한다.
    - *recipe*이라고도 한다.

# Practice1: automatic compile
- `main.c`, `sum.c`, `sum.h`의 소스코드를 가지고 자동으로 컴파일하도록 하는 makefile을 만든다.

<details><summary>코드 상세</summary>
<div markdown="1">

```main.c
// main.c
#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

int main(int argc, char *argv[]) {
    int c;
    c = sum(1, 2);
    printf("The sum of 1 and 2 is %d\n", c);
    exit(0);
}
```
```sum.c
// sum.c
int sum(int a, int b) {}
    int c;
    c = a + b;
    return c;
```
```c
// sum.h
#ifndef _SUM_H_
#define _SUM_H_

int sum(int a, int b);

#endif
```

</div></details>

- 위 파일들을 컴파일하고 링크하기 위해서 원래 다음과 같은 `gcc` 명령어를 입력해주어야 한다.
```shell
gcc -c sum.c
gcc -c main.c

gcc -o main sum.o main.o
```
```shell
./main
```
- 하지만 매번 저걸 반복하기는 힘들다. 아래는 `makefile`로 컴파일하는 코드이다.
```shell
// makefile
main: main.o sum.o
    gcc -o main main.o sum.o
sum.o: sum.c
    gcc -c sum.c
main.o: main.c
    gcc -c main.c
```
```shell
vi makefile
make
./main
```
