# Learning-C — repository of small C examples

This repository contains small, focused C programs organized by topic to help learn basic C language concepts. Each folder contains one or more example programs; below is a short summary of each file.

## 1.variable

- `1.variable.c` — Demonstrates basic variable declarations (int, char, float, double) and prints them using printf.
- `2.typeConversion.c` — Shows implicit and explicit type conversions (casting) between integer, char, float, and double.
- `3.constant.c` — Example of a `const` variable (read-only) and attempting to modify it (commented out).

## 2.operator

- `1.arithmetic.c` — Simple arithmetic example: divides a float by an int and prints the result.

## 3.dataTypes

- `1.dataType.c` — Lists common C data types with printf format specifiers. Shows examples, printing values and sizes (with `sizeof`) and a pointer example.
- `2.unsigned.c` — Reads and prints an `unsigned int` from input, with a brief comment about wrapping behavior.

## 4.ifElse

- `1.ifElse.c` — Reads an integer and demonstrates `if`, `else if`, and `else` branching with printed messages.

## 5.switch

- `1.switch.c` — Two `switch` examples: one with integer cases and one with character cases, both showing `case` and `default`.

## 6.loop

- `1.while.c` — `while` loop that prints "hello" 10 times.
- `2.doWhile.c` — Two `do..while` examples: one that runs once even when condition false, and another that counts from 0 to 9.
- `3.forLoop.c` — `for` loop printing 0..9 with a 1-second sleep between iterations, then prints the final value of the loop variable.

## 7.breakContinue

- `1.break.c` — Demonstrates `break` inside a `for` loop to exit early. Also shows an unreachable `printf` after `break` in another loop.
- `2.continue.c` — Demonstrates `continue` in `for` and `while` loops; shows that code after `continue` in the same iteration is skipped.

## 8.array

- `1.array.c` — Array examples: initialization styles, passing array to a function, reading values from input, and printing elements. Contains some intentional out-of-bounds demonstration when printing with a larger size.
- `2.arraySize.c` — Demonstrates `sizeof` on an array and an example of an empty zero-length array (compiler-dependent).
- `3.multiDimensional.c` — Starts examples for 1D and 2D arrays. Note: the file contains mismatched sizes and a missing semicolon or braces that may need fixing.

## 9.string

- `1.string.c` — Various ways to create strings, using `strcpy`, reading dynamic-length input into a variable-length buffer (using a runtime `n`), and printing strings.
- `2.strFunc.c` — String functions: `strcat`, `strcmp`, `strlen`, and reading user input into a runtime-sized buffer to compare strings.

## 10.userInput

- `1.scanf.c` — (file exists in folder) Example using `scanf` to read formatted input (not included above in summaries because file content was read earlier).
- `2.fgets.c` — (file exists in folder) Example using `fgets` to read a line of input (not included above in summaries because file content was read earlier).
