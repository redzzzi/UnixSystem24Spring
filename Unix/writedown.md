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
