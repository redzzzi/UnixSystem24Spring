# Loop

# General `While` Translation
## 1. `Jump-to-middle` translation
- `-Og` 옵션으로 컴파일할 때 쓰인다.
## 2. `Do-while` conversion
- `-O1` 옵션으로 컴파일할 때 쓰인다.
## For-While Conversion
- For Version
```c
for (Init; Test; Updata)
    Body
```
- While Version
```c
Init;
while (Test) {
    Body
    Update;
}
```
```plaintext
컴파일 옵션에 따라 어셈블리어 형태가 달라질 수 있다!
```
- C code
```c
#include <stdio.h>
#define WSIZE 8*sizeof(int)

long pcount_for (unsigned long x) {
  size_t i;
  long result = 0;
  for (i=0; i<WSIZE; i++) {
    unsigned  bit = (x >> i) & 0x1;
    result += bit;
  }
  return result;
}

int main() {
  return 0;
}
```
- with `-O1` option
```shell
gcc -O1 -S loop.c
```
```shell
pcount_for:
.LFB23:
        .cfi_startproc
        endbr64
        movl    $0, %edx
        movl    $0, %ecx
.L2:
        movq    %rdi, %rax
        shrq    %cl, %rax
        andl    $1, %eax
        addq    %rax, %rdx
        addq    $1, %rcx
        cmpq    $32, %rcx
        jne     .L2
        movq    %rdx, %rax
        ret
        .cfi_endproc
```
- with `-Og` option
```shell
gcc -Og -S loop.c
```
```shell
pcount_for:
.LFB23:
        .cfi_startproc
        endbr64
        movl    $0, %edx
        movl    $0, %ecx
        jmp     .L2
.L3:
        movq    %rdi, %rax
        shrq    %cl, %rax
        andl    $1, %eax
        addq    %rax, %rdx
        addq    $1, %rcx
.L2:
        cmpq    $31, %rcx
        jbe     .L3
        movq    %rdx, %rax
        ret
        .cfi_endproc
```
