# The GNU Debugger (GDB)
- 프로그램이 실행되는 동안 안이 어떤 식으로 돌아가는지 알 수 있도록 해준다.

## Main debugger operations
- 소스코드를 단계별로 살펴볼 수 있게 해준다.
    - `Breakpoints`
    - `Single-Stepping`
    - `Resume operation`
    - `Temporary breakpoints`
- 변수를 검사해준다.
- 변수에 대해 바뀐 사항을 알려준다.
- Call Stack을 위아래로 이동한다.

## Debugging Symbols
- Debugging Symbol Table은 컴파일된 프로그램에서 소스코드의 변수, 함수, 명령줄에 대응하여 instruction을 매핑한다.
- 프로그램에 내장되어 있을 수도, 개별 파일로 저장되어 있을 수도 있다.

## How to use *gdb*
- 컴파일 시 `-g` 옵션을 붙여줘야 한다.
1. Construct a debugging symbol table
- 아래 명령어로 컴파일하면 `a.out`의 결과물이 나온다.
```shell
gcc -g filename
```
2. Initiate a debugging session
- `$ gdb program`: 프로그램을 디버깅 세션으로 시작한다.
    - ex) gdb a.out
- `$ gdb program core`: 코어 덤프 파일을 디버깅한다.
- `$ gdb program 1234`: 실행 중인 프로세스를 디버깅한다. (프로세스ID가 1234라고 가정)
```shell
gcc -o <filename> -g <file>
```

### 여러 파일에 대한 디버깅 진행
```shell
$ gcc -g -Wall -c main.c swap.c
$ gcc -o swap main.o swap.o 
```

# GDB commands
| option | command | description |
| :---: | :---: | :--- |
| `b` | break | current line에 breakpoint를 건다. |
| `c` | continue | 다음 breakpoint나 error가 나타나지 않는 이상, 프로그램을 계속 실행시킨다. (중단된 위치부터 실행) |
| `d` | delete | breakpoint를 삭제한다. |
| `f` | frame | 스택 프레임을 보여준다. |
| `h` | help | command에 대한 도움말을 보여준다. |
| `i` | info | 디버깅에 유용한 정보를 제공한다. | 
| `l` | list | 소스코드를 나열한다. |
| `n` | next | 현재 줄의 코드를 한 단계 실행한다. s와 비슷하나, 함수 호출 포함 시 함수의 내부에 들어가지 않고 그 함수의 모든 코드를 실행한 후에 다음 줄로 이동한다는 차이점이 있다. |
| `p` | print | 현재 변수의 current value를 출력한다. |
| `q` | quit | gdb를 종료한다. |
| `r` | run | breakpoint 또는 error 전까지 프로그램을 실행한다. (처음부터 시작)|
| `s` | step | 현재 줄 코드를 한 단계 실행한다. 현재 줄이 함수 호출을 포함한 경우, 함수 내부로 들어가 첫 번째 줄을 실행한다. |
| `bt` | backtrace 1 | 함수가 어떤 순서로 호출되었는지 보여준다. |
| `up` | up | 프레임을 위로 이동시킨다. |

## Resuming Execution
- single stepping: `step`, `next`
    - 단순하게 다음 단계로 넘어가는 명령어 (물론 둘 사이 차이 있음)
- unconditionally resume execution: `continue`

# Commands related to stacks
- `backtrace`, `up`, `info frame`, `frame`, `info locals`, `info args`

## Detour
- ***segmentation fault***
    - 프로그램이 허용되지 않은 메모리에 접근하려할 때 발생시키는 메시지
- ***core dump***
    - 문제적인 프로그램에서 무엇이 잘못됐는지 파악하기 위해 생성하는 프로그램 메모리의 복사본
