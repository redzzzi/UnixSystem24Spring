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