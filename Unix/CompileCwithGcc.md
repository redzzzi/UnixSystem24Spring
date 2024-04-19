# gcc
- GNU C/C++ Compiler를 나타낸다.
- gcc는 다음 사항을 수행한다.
    - `preprocessing`, `compilation`, `assembly`, `linking`

# C/C++ source files **suffix**es
- `.cpp`, `.cc`, `.c`
    - 전처리, 컴파일, 어셈블될 **C++ 프로그램**에 쓰인다.
- `.c`
    - 전처리, 컴파일, 어셈블될 **C 프로그램**에 쓰인다.
    - 
- `.h` or `전처리(헤더) 파일`

# 파일 구조
- `.cpp`, `.cc`, `.c`와 같은 **실행 파일**
    - 메소드가 실행된다.
- `.h`와 같은 **인터페이스 파일**
    - 메소드와 클래스가 정의되어 있다.
    - **헤더파일**이라고도 불린다.
```plaintext
실행 파일은 인터페이스(헤더) 파일과 종속관계이다.
- 인터페이스는 프로토타입과 정의를 갖춘다.
- 실행은 실제 코드를 갖춘다.
```

# C workflow
1. 에디터 또는 IDE로 편집한다. -> **Source** files(`.c`, `.h`)
2. 전처리 과정을 거친다. (`.i`)
2. 컴파일을 한다. (`-s`)
3. 어셈블을 한다. -> **Object** files(`.o`)
3. 링크를 통해 실행파일을 생성한다. -> **Execution** file

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/c2e04076-d216-4f51-93b1-f8c0349ff779)

# C to Machine Code
## C compiler: `gcc -S`
    - C source file -> Assembly file
## Assembler: `gcc -c` or `as -c`
    - Assembly file -> Machine code
    - 다만, `as`를 사용했을 때는 파일이 `a.out`의 형식으로 나온다.
## C compiler: `gcc -c`
    - C source file -> Assembly file -> Machine code

# Compiling Multi-file Programs
- ***linker***는 다양한 오브젝트 파일과 정적으로 링크된 라이브러리를 결합하여 실행가능하도록 만든다.

# gcc options
| Options | Description |
| :---: | :--- |
| `-c` | linking 없이 소스파일의 컴파일과 어셈블을 실행한다. |
| `-o` *filename* | *filename*으로 출력물을 위치한다. 기본값은 `a.out`이다. |
| `-g` | 생성된 오브젝트 코드에 대한 디버깅 정보를 포함한다. |
| `-S` | 어셈블리 코드(*.s) 생성을 특정한다. |
| `-Wall` | 잘못된 코드와 관련된 모든 경고사항을 표시한다. |

<details><summary>Extra options</summary>
<div markdown="1">

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/78ff6e70-4823-4520-8291-4f6779e1da97)

</details>

# Compile a C program
## Method 1
- `a.out`<sub><i>(파일 이름 기본값)</i></sub>을 생성한다.

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/ca4c8b4d-0dd1-4b1a-9d4a-9ac8221dbdd1)
## Method 2
- `.c` 파일을 `.o` 파일로 컴파일한다.
- 링크 오브젝트 파일을 실행가능한 상태로 만든다.

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/cd713d0c-c9e8-4abd-a565-503ae4e4d8c9)

# Libraries
## Static libraries
- 프로그램이 실행되기 **이전 또는 그때** executable한 프로그램에 포함된다.
- `.a` 확장자를 가진다.
## Shared libraries
- 프로그램 시작 시 로드되며, 다양한 프로그램과 공유될 수 있다.
- 보통 리눅스에서 `.so` 확장자를 가진다.
## Dynamically loaded libraries
- executable한 프로그램이 실행되는 동안에 로드된다.

# Static binding
- 객체의 타입이 컴파일러에 의해 **컴파일 되는 시점**에 결정되는 것을 뜻한다.
- ***binding***이란 메소드에 대한 **호출**과 실제 구현된 메소드의 **코드**가 연결되는 것을 뜻한다.
- `-static`: static library를 링크한다.
```cpp
gcc -static file.c
```

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/c633211d-9a91-40cc-9d16-9b70b9b58f05)
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/85eab98e-c886-4eec-8e52-bf134f913922)

# Define the **symbol** from outside
- 예시
    - 아래 코드를 통해 2024가 출력된다.
```c
// example.c
#include <stdio.h>
int main() {
    printf("%d\n", VALUE);
    return 0;
}
```
```shell
gcc -DVALUE=2024 example.c
```

# Conditional compile
- `#ifdef DEBUG`
- `#endif`

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/177747ba-60d1-439a-817e-5c5a8a0acc07)

# Standard header file directory
- 원래 소스코드에서 헤더파일을 쓰고자 한다면, 아래 경고문에서 제시된 것처럼 헤더파일을 `" "`로 묶어줘야 한다.
- 그러나 `-I` 옵션을 gcc에게 **헤더파일을 찾도록 명령**한다.
    - `.`은 현재 디렉토리를 뜻한다.

![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/54d38d05-0b5d-46fb-b1b1-5e3c4c2c32c0)
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/68230938-bacb-4bd3-8957-f61ea178847d)
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/108fdb81-09de-447d-a8ed-ed631f10a2dc)

# Standard headers and libraries
- ***표준 헤더파일***은 다음 경로에서 확인 가능하다. `/usr/include`
- ***표준 라이브러리***는 다음 경로에서 확인 가능하다. `/usr/lib`
    - `.a`, `.so`? 각각 정적 라이브러리, 동적 라이브러리를 뜻함을 위해서 살펴보았다.
    - `-print` 옵션을 안 써도 출력은 같지만, 관습적으로 써준다.
    - `grep`은 키워드를 강조해준다.
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/74b8467a-c6d6-4eeb-b55b-d55aad0a3e4d)

