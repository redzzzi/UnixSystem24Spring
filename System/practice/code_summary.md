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
