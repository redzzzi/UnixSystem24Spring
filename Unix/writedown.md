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
### 표준 출력의 리디렉션 - to redirect standard output to another file
- ```명령어1```을 실행하여 나오는 출력물을 `파일1`로 내보낸다.
    - **기존에 파일1이 존재하는 경우** <ins>기존의 파일 내용은 지우고 새롭게 추가</ins>된다.
    - 키보드 이용과는 별개이다.
```shell
명령어1 > 파일1
```
- 파일 끝에 출력물을 추가한다.
    - Using the `>>` operator will result in the output being appended to the file.
```shell
명령어1 >> 파일1
```
### 표준 입력의 리디렉션
- ```명령어1```을 실행하되, `파일1`이 입력의 대상이 된다.
    - 키보드 이용과는 별개이다.
```shell
명령어1 < 파일1
```
### 혼합
- `명령어`은 `들어오는파일`에서 내용을 불러들인 뒤 `나가는파일`에 기록한다.
```shell
명령어1 < 들어오는파일 > 나가는파일
```
