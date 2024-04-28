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

## While Loop
```c
long pcount_while (unsigned long x) {
    long result = 0;
    while (x) {
        result += x & 0x1;
        x >>= 1;
    }
    return result;
}
```
### Jump-to-middle translation
```c
long pcount_goto_jtm (unsigned long x) {
    goto test;
   loop:
    result += x & 0x1;
    x >>= 1;
   test:
    if (x) goto loop;
    return result;
}
```

## While Loop 2
### Do-while conversion
```c
long pcount_goto_dw (unsigned long x) {
    long result = 0;
    if (!x) goto done;
   loop:
    result += x & 0x1;
    x >>= 1;
    if (x) goto loop;
   done:
    return result;
}
```

# For Loop Form
```c
#define WSIZE 8*sizeof(int)
long pcount_for (unsigned long x) {
    size_t i;
    long result = 0;
    for (i = 0; i < WSIZE; i++) {
        unsigned bit = (x >> i) & 0x1;
        result += bit;
    }
    return result;
}
```
## For-While Conversion
```c
#define WSIZE 8*sizeof(int)
long pcount_for_while (unsigned long x) {
    size_t i;
    long result = 0;
    i = 0;
    while (i < WSIZE) {
        unsigned bit = (x >> i) & 0x1;
        result += bit;
        i++;
    }
    return result;
}
```
## For Loop -> Do-While Conversion
```c
#define WSIZE 8*sizeof(int)
long pcount_for_goto_dw (unsigned long x) {
    size_t i;
    long result = 0;
   loop:
    unsigned bit = (x >> i) & 0x1;
    result += bit;
    if (x) goto loop;
   i++;
   if (i < WSIZE) goto loop;
   done:
    return result;
}
```

# Switch Statement
```c
long switch_eg (long x, long y, long z) {
    long w = 1;
    switch (x) {
    case 1:
        w = y * z;
        break
    case 2:
        w = y / z;
    case 3:
        w += z;
        break;
    case 5:
    case 6:
        w -= z;
        break;
    default:
        w = 2;
    }
    return w;
}
```
```c
// %rdi | x
// %rsi | y
// %rdx | z
// %rax | return value
swich_eg: // note that w IS NOT INITIALIZED HERE
    movq   %rdx, %rcx
    cmpq   $6, %rdi
    ja     .L8
    jmp    *.L4(, %rdi, 8)
.section   .rodata
    .align 8
.L4:
    .quad  .L8 // x = 0
    .quad  .L3 // x = 1
    .quad  .L5 // x = 2
    .quad  .L9 // x = 3
    .quad  .L8 // x = 4
    .quad  .L7 // x = 5
    .quad  .L7 // x = 6
.L3: // case 1
    movq   %rsi, %rax
    imulq  %rdx, %rax
    ret
.L5: // case 2
    movq   %rsi, %rax
    cqto
    idivq  %rcx
    jmp    .L6 // goto merge
.L9 // case 3
    movl   $1, %eax
.L6:
    addq   %rcx, %rax
    ret
.L7:
    movl   $1, %eax
    subq   %rdx, %rax
    ret
.L8:
    movl   $2, %eax
    ret
```
