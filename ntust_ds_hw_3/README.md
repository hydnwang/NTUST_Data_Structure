# Data Structures HW 3

### OS

macOS High Sierra (Version 10.13.1)

### IDE

Visual Studio Code (Version 1.18.0)

### Compiler

g++ (C++11)

```shell
$ g++ -g -std=c++11 -o hw3.exe main.cpp
```

### 包含檔案

* Source code
  * main.cpp
  * func.cpp
  * poly.h
* Execution file
  * hw3.exe

### 程式執行步驟示範

1. **輸入4個數字並以空白為間隔建立多項式：**

```shell
$ Construct a polynomial using 4 digits separated by single space:
$ > Enter coefficient and exponents (coef, ex, ey, ez), or q to quit: 4 10 3 2
$ > Enter coefficient and exponents (coef, ex, ey, ez), or q to quit: 2 8 3 2
$ > Enter coefficient and exponents (coef, ex, ey, ez), or q to quit: 3 0 2 2
$ > Enter coefficient and exponents (coef, ex, ey, ez), or q to quit: 1 4 4 1
$ > Enter coefficient and exponents (coef, ex, ey, ez), or q to quit: q
```

2. **選擇要執行的功能(`1) retCoeff(ex, ey, ez)` or `2) Mulf(ex, ey, ez)`)或是輸入 `q` 退出：**

```shell
$ => Choose a function to execute:
$ 1) retCoeff(ex, ey, ez) => Return a coefficent
$ 2) Mulf(ex, ey, ez) => Multiply polynomial by exponents
$ q) Quit
$ 1
$ > Enter exponents (ex, ey, ez), or q to quit: 8 3 2
$ retCoeff(8, 3, 2): 2

$ => Choose a function to execute:
$ 1) retCoeff(ex, ey, ez) => Return a coefficent
$ 2) Mulf(ex, ey, ez) => Multiply polynomial by exponents
$ q) Quit
$ 2
$ > Enter exponents (ex, ey, ez), or q to quit: 0 1 2

$ => Choose a function to execute:
$ 1) retCoeff(ex, ey, ez) => Return a coefficent
$ 2) Mulf(ex, ey, ez) => Multiply polynomial by exponents
$ q) Quit
$ 1
$ > Enter exponents (ex, ey, ez), or q to quit: 0 3 4
$ retCoeff(0, 3, 4): 3

$ => Choose a function to execute:
$ 1) retCoeff(ex, ey, ez) => Return a coefficent
$ 2) Mulf(ex, ey, ez) => Multiply polynomial by exponents
$ q) Quit
$ q
```

