# 07-1. Source code version control with git

## Version control
- 특정 버전을 이후에 불러올 수 있도록 파일 또는 파일 모음에서의 변화 사항을 기록하는 시스템

### (<u>Local Version</u> VS. <u>Centralized Version<u/> VS. <u>Distributed Version</u>) Control Systems
- **Local Version**은 revision control 하에, 파일의 모든 변경 사항을 간단한 DB에 가지고 있다.
- **Centralized Version**
    - ***repository***: a **single** authoritative data source
    - *check-out*과 *check-in*이 모두 해당 central repository를 참조하여 이루어진다.
    - examples: CVS<sup>Concurrent Version System</sup>, SVN<sup>Subversion</sup>
- **Distributed Version**
    - 어떤 하나의 repository가 authoritative하진 않는다.
    - 데이터가 어떤 repository이든 check in/out될 수 있다.

## Git
- open source
- *Distributed* version control s/w
- Remote server hosts your repo
- Users maintain a local copy of the entire repo
- created by *Linus Torvalds*

### 3 states of git
- `committed`: 데이터가 로컬 DB에 안전하게 저장되었다.
- `modified`: 파일을 수정하였으나 commit 되지 않은 상태이다.
- `staged`
    - current version에서 수정된 파일을 next commit하겠다고 표시한다.
    - stage된 파일은 next commit에 포함될 것이다.

- `.git directory`: 깃은 프로젝트에 대한 metadata와 object DB를 저장한다.
- `working tree`: 프로젝트에서 checkout할 수 있는 곳이다.
- `staging area`: 다음 커밋이 어떻게 될지에 대한 정보를 담고 있는 파일이다.  보통 Git dir에 포함되어 있다.

## The basic Git workflow
1. working dir에서 파일을 수정한다.
2. staging하고 싶은 버전을 staging area에 추가하면서 파일을 staging한다.
3. staging area에 있는 파일들을 가져가서 해당 버전을 Git dir에 영구적으로 저장하도록 하는 commit을 한다.

## git 설치 명령어
- Ubuntu
```shell
sudo apt-get install git-all
```
- Fedora
```shell
sudo yum install git-all
```
- *`apt-get`에서 에러가 발생한다면??*
    1. 제시된 파일을 지운다. `sudo rm -rf /var/lib/dpkg/lock`
    2. 업데이트 시킨다. `sudo apt-get update && sudo apt-get install git-all`

## Configure git (깃 초기 설정)
- 이름 설정: `git config --global user.name "<이름>"`
- 이메일 주소 설정: `git config --global user.email "<주소>"`
    - 위 과정은 `~/.gitconfig` 수정을 통해서도 가능하며, 파일 수정을 추천한다.
- 설정 확인: git config --list

## Utilizing a git Repo
1. 기존 디렉토리를 레포지토리로 초기화한다.
- 새로 만들어도 되고, 기존 것 써도 됨.
- `git init`: Git repo의 기본이 되는, repository 파일의 모든 것을 담고 있는 `.git` 하위 디렉토리를 생성해준다.
2. `git clone <remote address>`
- 클론한 레포 이름으로 디렉토리가 생성된다.
- `.git` 디렉토리 내부를 초기화한다.
- 해당 레포의 모든 데이터를 가지고 온다.
- 최신 버전의 복사본으로 checkout 한다.
3. `git status`
4. `git add`: begins tracking a new file
5. `git commit`
- staging area는 내가 원하던 대로 만들어졌다. 이제 변경 사항을 커밋할 차례이다.

# 07-2. GitHub
- `git remote`: which remote servers you have configured
    - `git remote -v`: Git이 나중에 쓰려고 저장해놓은 원격 레포 리스트
        - shortname은 origin, main같은 별명을 뜻함
    - `git remote add <shortname> <url>`: 참조하고자 하는 원격 레포를 추가하고 싶을 때
- `git fetch <remote-name>`: ***get data*** from your remote projects
    - 데이터는 **로컬 레포로만** 다운로드 할 수 있음 
    - 깃클론을 할 때, 명령어는 origin이라는 이름으로 해당 원격 레포를 자동으로 추가한다.
- `git pull`: remote branch를 current branch로 **fetch&merge**
- `git push <remote-name> <branch-name>`: 프로젝트를 공유하고 싶은 시점에 upstream으로 push 해주어야 한다.
- `git push origin main`
