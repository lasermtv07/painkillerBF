# painkillerBf

**(C) lasermtv07 - GNU GPL licence**
## Intro
**painkillerBF** is a programming language/preprocessor designed to make **brainfuck programming** easier. However, it kinda **failed** and I thought of cancelling
it entirely, but Im pushing this code and if u feel like fixing it, submit a pullrequest

## Installation
Clone the repo and build it yourself *makefile is with GCC for linux* Then just run **main.out** with the source file.
## Docs
### pair function

- `'text'` - print to console D
- `*text*` - a comment D

### simple functions

- `-vn` - decrement by fixed value **D**
- `^n` - increment by fixed value - u must put *something* after the value that is not another `+` or `-`  D

### subroutines

- `n(code)` - declare a subroutine with *code* representing the program+ and assign it as instruction to letter *n*. The routine also runs minimally once, whens it defined.
- `n` - load the subroutine , in preprocessing
- ~~`_name` - import a file with name *name~~* - *DOES NOT WORK - COMMENTED. SUBMIT PULL REQUEST IF U WANNA FIX*
