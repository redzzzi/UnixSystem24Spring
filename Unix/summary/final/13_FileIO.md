- example codes

# Character I/O functions
- Reading a character from a file
```c
#include <stdio.h>
int getc(FILE *fp);
int fgetc(FILE *fp);
int getchar(void);
```
- Writing a character to a file
```c
#include <stdio.h>
int putc(int c, FILE *fp);
int fputc(int c, FILE *fp);
int putchar(int c);
```

# Example1
- stdin and stdout
```c
#include <stdio.h>

int main() {
    int c = fgetc(stdin); // 키보드로 입력받은 ASCII code를 읽는다. (R)
    while (c != EOF) { // 입력받은 문자가 끝날 때까지 아래 코드 실행
        fputc(c, stdout); // c의 값을 stdout file에 쓴다. (W)
        c = fgetc(stdin); // 키보드로 입력받은 새로운 문자를 읽는다. (R)
    }
}
```

# Example2: character-based I/O
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    fp = fopen(argv[1], "w"); // write mode
    c = fgetc(stdin); // read ASCII code from the keyboard (R)
    while (c != EOF) {
        putc(c, fp); // fp 포인터가 가리키는 파일로 c의 값을 쓴다. (W)
        c = fgetc(stdin); // (R)
    }
    printf("A write operation to %s is completed.\n", argv[1]);
}
```
<p align="center">
    <img src="https://github.com/redzzzi/UnixSystem24spring/assets/127263392/f05cc7e5-14c5-4775-a26b-7821b8f9ad74" width="500" />
</p>
