# Command
- `sort`
- `grep`
- `cmp`
- `diff`
- `find`

- `find / -size 0 -exec rm -i {} \;`

# Standard **Input**, **Output**, and **Error**
```plaintext
Everything is a file.
```
- Many programs produce **output** of some kind.
    - `stdout`: their **results** to a special file
        - *standard output*
    - `stderr`: their **status msg** to another file
        - *standard error*
- Many programs take **input** from a facility called `stdin`. 
    - 기본적으로 키보드에 붙어있음

# I/O redirection
- `output`이 어디로 갈지, `input`이 어디에서 올 지 바꿀 수 있도록 한다. 
    - 보통 `output` -> screen, `input` -> keyboard
- 입출력 명령어로, 파일 간 리디렉션을 할 수 있다.
```plaintext
여러 명령어를 연결하여 pipeline command로도 이용할 수 있다.
```

## [redirection](https://ko.wikipedia.org/wiki/%EB%A6%AC%EB%8B%A4%EC%9D%B4%EB%A0%89%EC%85%98)
### **표준 출력**의 리디렉션 - to redirect standard output to another file
- ```명령어1```을 실행하여 나오는 출력물을 `파일1`로 내보낸다.
    - **기존에 파일1이 존재하는 경우** <ins>기존의 파일 내용은 지우고 새롭게 추가</ins>된다.
    - 키보드 이용과는 별개이다.
```shell
[명령어1] > [파일1]
```
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/36469bb0-33a5-45cf-b3c8-6ff5ef6c9cf4)

- 파일 끝에 출력물을 추가한다.
    - Using the `>>` operator will result in the output being appended to the file.
```shell
[명령어1] >> [파일1]
```
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/abebc08f-939a-421c-a22c-fd9b595ec5a2)

### **표준 입력**의 리디렉션
- <ins>키보드에서 파일</ins>이라는 표준 입력의 소스를 바꿀 수 있다.
- ```명령어1```을 실행하되, `파일1`이 입력의 대상이 된다.
    - 키보드 이용과는 별개이다.
```shell
[명령어1] < [파일1]
```
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/b528ef65-0876-468f-98de-47b2ee9651a7)

### 혼합
- `명령어`은 `들어오는파일`에서 내용을 불러들인 뒤 `나가는파일`에 기록한다.
```shell
[명령어1] < [들어오는파일] > [나가는파일]
```

## Redirecting **Standard Error**
- 표준 에러를 리디렉션 하려면 *file descriptor*를 참고해야 한다.
- **stdin**: `0`, **stdout**: `1`, **stderr**: `2`
### using *file descriptor*
- `명령어` > `파일`과 같은 의미로, 표준 출력을 `파일`에 덮어쓴다.
```shell
[명령어] 1 > [파일]
```
- `명령어` 실행 시, **에러가 발생**한다면, 에러 내용을 `파일`에 덮어쓴다.
```shell
[명령어] 2 > [파일]
```
- `명령어` 실행 시, **결과**는 `파일`에, **에러**는 `파일 2`에 덮어쓴다.
```shell
[명령어] 1 > [파일] 2 > [파일2]
```
- `명령어` 실행 시, 표준 출력과 표준 에러를 모두 `파일`에 쓴다. 
```shell
[명령어] 1 > [파일] 2 > [파일]
```

# Disposing of **Unwanted Output**
- 명령어 출력물을 버리고 싶다면 아래 예제처럼 실행하면 된다.
- 바로 output을 `/dev/null`이라고 부르는 **special file**에 리디렉팅한다.
    - 입력은 받지만 아무것도 하지 않는다.
```shell
$ ls -l /bin/usr 2 > /dev/null
```
