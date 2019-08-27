# Data Structures HW1

### OS

macOS Sierra (Version 10.12.6)

### IDE

Visual Studio Code (Version 1.16.1)

### Compiler

g++ (C++11)

### 包含檔案

* **Source code**
  * hw1.cpp
  * matrix.h
* **Execution file**
  * hw1.exe
* **Readme file**
  * README.md

### 操作步驟

1. 程式提示使用者依次輸入英文字母 [a-z]，一次一列，輸入完後程式會顯示剛剛輸入的矩陣。
2. 程式提示輸入一串字母作為搜尋的 pattern，請輸入最多10個英文字母。
3. 程式詢問是否要讓被搜尋過的字母可以重複使用，輸入 y 代表可以重複，n 代表不能，預設為 y。
4. 程式輸出結果。
5. 實際執行畫面如下：

```bash
The size of the matrix is: 100
Please input a series of characters from a to z for row[0] of the matrix:
qwe
[Warning] Input string is too short, string must be 10 characters long, please try again:
qwertyuiop[]
[Warning] Input string contains characters out of a to z, please try again:
qwertyuiop
Please input a series of characters from a to z for row[1] of the matrix:
qwertyuiop
Please input a series of characters from a to z for row[2] of the matrix:
qwertyuiop
...
(skip)
...

The matrix you just input is:
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |
| q w e r t y u i o p |

Find a pattern by entering no more than characters from a to z:
qwertyuiop
Reuse characters found in matrix to match your pattern? (y/n, default:y):
y
Output: (0,0),(0,1),(0,2),(0,3),(0,4),(0,5),(0,6),(0,7),(0,8)
```

