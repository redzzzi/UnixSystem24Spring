# 04 machine basics
## 1. `sum.c` and inner functions `sumstore`'s assembly code
```c
// sum.c
#include <stdio.h>
#include <stdlib.h>

long plus(long x, long y) {
    return x + y;
}

void sumstore(long x, long y, long *dest) {
    long t = plus(x, y);
    *dest = t;
}

int main(int argc, char *argv[]) {
    long x = atoi(argv[1]);
    long y = atoi(argv[2]);
    long z;
    sumstore(x, y, &z);
    printf("%ld + %ld --> %ld\n");
    return 0;
}
```
```c
// sumstore.s
sumstore:
    pushq %rbx
    movq  %rdx, %rbx
    call  plus
    movq  %rax, (%rbx)
    popq  %rbx
    ret
```

## 2. swap()
```c
void swap(long *xp, long *yp) {
    long t0 = *xp;
    long t1 = *yp;
    *xp = t1;
    *yp = t0;
}
```
```c
swap:
    movq (%rdi), %rax
    movq (%rsi), %rdx
    movq %rdx, (%rdi)
    movq %rax, (%rsi)
    ret
```

## 3. arith()
```c
long arith(long x, long y, long z) {
    long t1 = x + y;
    long t2 = z + t1;
    long t3 = x + 4;
    long t4 = y * 48;
    long t5 = t3 + t4;
    long rval = t2 * t5;
    return rval;
}
```
```c
arith:
    movq (%rdi, %rsi), %rax
    addq %rdx, %rax
    leaq (%rsi, %rsi, 2), %rdx
    salq 4, %rdx
    leaq 4(%rdx, %rdi), %rcx
    imulq %rcx, %rax
    ret
```

# 05 machine control
## greater than
```c
int gt(long x, long y) {
    return x > y;
}
```
```c
cmpq   %rsi, %rdi
setg   %al
movzbl %al, %eax
ret
```

## Exercise
```c
xorq   %rax, %rax
subq   $1, %rax
cmpq   $2, %rax
setl   %al
movzblq %al, %eax
```

| `%rax` | `SF` | `CF` | `OF` | `ZF` |
| :--- | :---: | :---: | :---: | :---: |
| 0x0000 0000 0000 0000 | 0 | 0 | 0 | 1 |
| 0xFFFF FFFF FFFF FFFF | 1 | 1 | 0 | 0 |
| 0xFFFF FFFF FFFF FFFF | 1 | 0 | 0 | 0 |
| 0xFFFF FFFF FFFF FF01 | 1 | 1 | 0 | 0 |
| 0x0000 0000 0000 0001 | 1 | 0 | 0 | 0 |

## Conditional Branch: absdiff
```c
long absdiff(long x, long y) {
    long result;
    if (x > y)
        result = x - y;
    else
        result = y - x;
    return result;
}
```
```c
// gcc -Og -S -fno-if-conversion absdiff.c
absdiff:
    cmpq %rsi, %rdi
    jle  .L4
    movq %rdi, %rax
    subq %rsi, %rax
    ret
.L4:
    movq %rsi, %rax
    subq %rdi, %rax
    ret
```
## Conditional Move: absdiff
```c
// gcc -O2 -S <파일명>
absdiff:
    movq   %rdi, %rax // x
    subq   %rsi, %rax // x - y
    movq   %rsi, %rdx
    subq   %rdi, %rdx // y - x
    cmpq   %rsi, %rdi
    cmovle %rdx, %rax
    ret
```

## "Do-While" Loop: Count number of 1's in arg x ("popcount")
```c
// do-while
long pcount_do (unsigned long x) {
    long result = 0;
    do {
        result += x & 0x1;
        x >>= 1;
    } while (x);
    return result;
}
```
```c
// goto
long pcount_goto (unsigned long x) {
    long result = 0;
    loop:
        result += x & 0x1;
        x >>= 1;
    if (x) goto loop;
    return result;
}
```
### ⭐⭐ 헷갈리는 거 조심!!
```c
    movl  $0, %eax
.L2:
    movq  %rdi, %rdx
    andl  $1, %edx
    addq  %rdx, %rax
    shrq  %rdi
    jne   .L2
    rep; ret
```
