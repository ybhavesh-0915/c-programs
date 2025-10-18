## 01. variable
- 1.variable.c — basic variable declarations and printing (int, char, float, double).
- 2.typeConversion.c — implicit and explicit type conversions and casts.
- 3.constant.c — demonstration of `const` variables and input reading.

## 02. operator
- 1.arithmetic.c — simple arithmetic example showing division between float and int.

## 03. dataTypes
- 1.dataType.c — overview of common C data types, their format specifiers, example prints, and `sizeof` checks.
- 2.unsigned.c — reads and prints an `unsigned int` with a note on wrapping behavior.

## 04. ifElse
- 1.ifElse.c — example demonstrating `if`, `else if`, and `else` branching based on an input integer.

## 05. switch
- 1.switch.c — integer and character `switch` examples including `case` and `default` handling.

## 06. loop
- 1.while.c — simple `while` loop printing a string multiple times.
- 2.doWhile.c — `do..while` examples (one-run case and counting loop).
- 3.forLoop.c — `for` loop examples with `sleep()` showing loop variable behavior.

## 07. breakContinue
- 1.break.c — demonstrates `break` to exit loops early.
- 2.continue.c — demonstrates `continue` skipping the remainder of an iteration.

## 08. array
- 1.array.c — array initializations, passing arrays to functions, and examples showing default/garbage values and input into arrays.
  - `printArr` — helper to print arrays.
- 2.arraySize.c — uses `sizeof` on arrays and shows a zero-length array example (compiler-dependent).
- 3.multiDimensional.c — starter code for 1D and 2D arrays (note: mismatch in sizes / braces that may need fixing).

## 09. string
- 1.string.c — multiple string initialization patterns, `strcpy`, and reading runtime-sized input into a buffer.
- 2.strFunc.c — uses `strcat`, `strcmp`, `strlen` and runtime buffer input and comparison.

## 10. userInput
- 1.scanf.c — thorough notes and examples on `scanf()` vs `fgets()`/`sscanf()`, buffer flushing, and safe patterns; includes:
  - `cleanBuffer` — utility that flushes stdin until newline or EOF.
- 2.fgets.c — example reading a full line with `fgets()` and parsing with `sscanf()`.

## 11. pointers
- 1.pointer.c — basic pointer usage, dereferencing, and address printing.
- 2.doublePointer.c — example of pointer-to-pointer (`int **`) and reassigning nested pointers.
- 3.arrayPointer.c — multiple ways to iterate arrays and print addresses/values (pointer arithmetic and indexing).

## 12. bitwise
- 1.bitwise.c — bitwise operators (`&`, `|`, `^`, shifts) demo and bit extraction loop.
- 2.booth.c — beginnings of a Booth multiplication implementation:
  - `bits` — converts integer to bit array.
  - `bitsCount` — computes number of bits needed.
  - `binAdd` — placeholder for binary add (not implemented).
  - `printarr` — prints bit arrays.

## 13. Function
- 1.function.c — recursion and helper examples:
  - `naturalSum` — recursive sum 1..n.
  - `factorial` — recursive factorial.
  - `ascii` — returns integer ASCII code for a `char`.
- 2.funcReturnArr.c — returning arrays/pointers from functions:
  - `ascii` — returns heap-allocated int array of ASCII codes.
  - `arrfunc` — returns static array.
- 3.funcWithStatic.c — demonstrates a function-level `static` variable:
  - `counter` — increments and persists between calls.

## 14. Files
- 1.file.c — demonstrates file handles and contrast between normal and `static` local file pointer functions:
  - `createFile` — opens a file and returns `FILE *`.
  - `createStaticFile` — opens a file into a `static FILE *`.
- 2.fileWrite.c — demonstrates writing and appending to a file using:
  - `createFile` — helper used to open files for `w` and `a`.
- 3.fileRead.c — opens a file for reading using:
  - `createFile` — same named helper for opening files.
- todo.txt — sample text (used by the file examples above).