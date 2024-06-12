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

# Example3: File copy with a character I/O
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char c;
    FILE *fp1, *fp2;

    fp1 = fopen(argv[1], "r"); // read mode
    if (fp1 == NULL) {
        printf("Error: Cannot open the file %s\n", argv[1]);
        exit(1);
    }
    fp2 = fopen(argv[2], "w"); // read ASCII code from the keyboard
    while ((c=fgetc(fp1)) != EOF) {
        fputc(c, fp2); // fp 포인터가 가리키는 파일로 c의 값을 쓴다.
    }
    fclose(fp1);
    fclose(fp2);
    printf("Copy from %s to %s is completed.\n", argv[1], argv[2]);
}
```

# Line-based I/O functions
- Reading entire lines of data from a file/stdin
```c
#include <stdio.h>

char *fgets(char *buf, int n, FILE *fp);
char *gets(char *buf);
```
- Writing entire lines of data to a file/stdout
```c
#include <stdio.h>

int fputs(const char *str, FILE *fp);
int puts(const char *str);
```

# Example4: Line I/O
```c
#include <stdio.h>
#define MAXLINE 80

int main(int argc, char *argv[]) {
    FILE *fp;
    int line = 0;
    char buffer[MAXLINE];
    if (argc != 2) {
        fprintf(stderr, "Usage: line filename\n");
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Usage: line filename\n");
        return 2;
    }
    while (fgets(buffer, MAXLINE, fp) != NULL) { // read one MAXLINE
        line++;
        printf("%3d %s", line, buffer); // print with a line number
    }
    fclose(fp);
}
```

# Formatted I/O functions
- Reading formatted data from a file
```c
#include <stdio.h>

int fscanf(FILE *stream, const char *format, ...)
```
- Writing a formatted string to a file
```c
#include <stdio.h>

int fprintf(FILE *stream, const char *format, ...)
```

Example: `fprint.c`
```c
#include <stdio.h>
#include "student.h"

int main(int argc, char **argv) {
    struct student record;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "w");
    while (scanf("%d %s %lf", &record.id, record.name, &record.score) == 3) {
        fprintf(fp, "%d %s %lf\n", record.id, record.name, record.score);
    }
    fclose(fp);
    return 0;
}
```
- `student.h`
```c
struct student {
    int id;
    char name[20];
    double score;
};
```

# Example: `fscanf.c`
```c
#include <stdio.h>
#include "student.h"

int main(int argc, char **argv) {
    struct student record;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    printf("%s %7s %6s\n", "Sno", "Sname", "Sgrade");
    while (fscanf(fp, "%d %s %lf", &record.id, record.name, &record.score) == 3) {
        printf("%d %s %lf\n", record.id, record.name, record.score);
    }
    printf("\n");
    fclose(fp);
    return 0;
```
