# 6.1 Debuggin with [GDB](https://www.tutorialspoint.com/gnu_debugger)
```
디버깅의 진가가 발휘될 때는 . . .
 코드를 비효율적으로 들여다보기만 할 필요가 없게 되었을 때,
  변수 검사 및 설정할 때,
   프로그램이 충돌했을 때,
   이다.....
```
# The GNU Debugger (GDB)
- 용도: 프로그램이 실행될 때 내부 다른 곳에서 어떤 일이 일어나는지 볼 수 있게 해준다.
- 기능
    1. 프로그램을 실행하고, 해당 behavior에 영향을 미치는 어떤 것이든 특정할 수 있다.
    2. special condition 하에 프로그램을 멈출 수 있다.
    3. 프로그램이 멈출 때, 함수를 주시한다.
    4. 프로그램에서 무언가를 바꿀 수 있다.

## Main debugger operations
### Stepping Through the Source Code
- `Breakpoints`, `Single-stepping`, `Resume operation`, `Temporary breakpoints`
### Inspecting Variables
### Monitoring Changes to a Variable
### Moving Up and Down the Call Stack

## Debugging Symbols
- **Debugging Symbol Table**
    - 컴파일된 binary program에 소스코드의 변수, 함수, 명령줄에 대응되는 instructions을 매핑한다.

# How to use gdb
1. Construct a *debugging symbol table*
```shell
gcc -g <filename>
```
2. To *initiate* a debugging session
```shell
$ gdb program
$ gdb program core
$ gdb program 1234
```
