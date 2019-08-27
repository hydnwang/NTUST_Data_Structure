# Data Structures HW 4

### OS

macOS High Sierra (Version 10.13.1)

### IDE

Visual Studio Code (Version 1.18.1)

### Compiler

g++ (C++11)

```shell
$ g++ -g -std=c++11 -o hw4.exe main.cpp
```

### 包含檔案

* Source code
  * main.cpp
  * func.cpp
  * bst.h
* Execution file
  * hw4.exe

### 程式執行步驟示範

1. Execute the program:

   ```shell
   $ ./hw4.exe
   ```

2. Construct a binary search tree

   ```shell
   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   5
   > Insert a sequence of element node(q: quit): 12 43 50 66 68 70
   ```

3. Insert new and existed element nodes

   ```shell
   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   1
   > Insert element node(q: quit): 34

   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   1
   > Insert element node(q: quit): 34
   element already existed(34)
   ```

4. Delete existed and non existed element nodes

   ```shell
   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   2
   > Delete element node(q: quit): 70

   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   2
   > Delete element node(q: quit): 70
   no match(70)
   ```

5. Print out the tree

   ```shell
   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   4
   12 34 43 50 66 68
   ```

6. Find minelement

   ```shell
   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   3
   > Threshold value(q: quit): 91
   Minimum element: 50

   => Choose a function to execute:
   1) Insert
   2) Delete
   3) Minelement
   4) Print tree
   5) Construct tree by massive input
   q) Quit
   3
   > Threshold value(q: quit): 300
   no such element
   ```

   ​