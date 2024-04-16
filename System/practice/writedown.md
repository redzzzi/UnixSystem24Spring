# Loop

# General `While` Translation
## `Jump-to-middle` translation
- `-Og` 옵션으로 컴파일할 때 쓰인다.
## `Do-while` conversion
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
