# Data Structures HW 5

### OS

macOS High Sierra (Version 10.13.1)

### IDE

Visual Studio Code (Version 1.18.1)

### Compiler

g++ (C++11)

```shell
$ g++ -g -std=c++11 -o hw5.exe main.cpp
```

### 包含檔案

* Source code
  * main.cpp
  * func.cpp
  * bst.h
* Execution file
  * hw5.exe

### 程式執行步驟示範

1. Execute the program:

   ```shell
   $ ./hw5.exe
   ```

2. Construct a binary search tree by entering a sequence of element nodes:

   ```shell
   ===================================
   * Construct binary tree (q: quit) *
   ===================================
   > 20 17 14 36 22 48 28
   ```

3. Print the tree, including the left size and the rank of each element, it can also be used to check the left size after element insertion and deletion:

   ```shell
   ==================================
   *  Choose a function to execute  *
   ==================================
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Avg
   q) Quit
   ==================================
   > 4  
   > Printing...
   |----------------------------|
   | Element | Left Size | Rank |
   |---------|-----------|------|
   |      14 |         1 |    1 |
   |      17 |         2 |    2 |
   |      20 |         3 |    3 |
   |      22 |         1 |    4 |
   |      28 |         1 |    5 |
   |      36 |         3 |    6 |
   |      48 |         1 |    7 |
   |---------|-----------|------|
   ```

4. Calculate the average from specified rank range, separate 2 input numbers by comma(,):

   ```shell
   ==================================
   *  Choose a function to execute  *
   ==================================
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Avg
   q) Quit
   ==================================
   > 5
   > enter rank range(l,u) (q: quit): 2,4
   > ( 17 + 20 + 22 ) / 3 = 19
   ```
