# ssh 접속
```shell
ssh 202355597@164.125.18.136 -p 8022
```

# scp 파일 전송
1. 파일 전송 전, `Remote File Path`를 확인한다.
2. 우선 **ssh**로 로그인을 한다.
3. 다음 명령어를 입력하여 확인한다.
```shell
du --max-depth=0 -h ~/
```
![스크린샷 2024-04-08 004136](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/f57cc950-d36d-45bf-aa6e-411eec2c4dd7)


4. 해당되는 원격 경로와 로컬 경로를 입력해서, 파일을 전송한다.
```shell
scp -r -P 8022 202355597@164.125.18.136:/home/sys060/202355597/ ./datalab
```
![image](https://github.com/redzzzi/UnixSystem24Spring/assets/127263392/bb04aea5-2c0c-4caf-9117-b34521740203)
