#include <stdio.h>


/*
# **C Input Handling – Full Chat Summary**


## 2️⃣ scanf() vs fget() Basics

* `scanf()` → reads typed input according to format (`%d`, `%s`)
* Stops at **whitespace** for `%s`
* Leaves leftover chars in **stdin buffer** (like `\n`) → next scanf/fgets may misread
* `fgets()` → reads **entire line** including spaces
* Buffer is **cleared up to newline**
* Use `sscanf()` to parse `fgets()` line into typed values

---

## 3️⃣ Input Buffer Issues

* After `scanf()`, newline or leftover chars remain → next input can read them unintentionally
* Example:

```c
scanf("%s", name);
scanf("%d", &age);  // may fail if buffer has leftover \n
```

* **Solutions**:

  1. Flush buffer manually:

  ```c
  while((c=getchar())!='\n' && c!=EOF);
  ```

  2. Use space before format specifier:

  ```c
  scanf(" %d", &age);
  ```

  3. Prefer `fgets()` + `sscanf()` for safe parsing

---

## 4️⃣ scanf vs fgets + sscanf – Core Difference

| Feature                 | scanf                                           | fgets + sscanf                |
| ----------------------- | ----------------------------------------------- | ----------------------------- |
| Reads from              | stdin                                           | fgets buffer                  |
| Handles spaces          | %s stops at space                               | reads full line               |
| Leaves buffer leftover? | Yes                                             | No                            |
| Error handling          | Stops at first mismatch, may leave buffer dirty | Return value checkable, safer |
| Best for                | Short, perfect input                            | User input / robust programs  |

* **scanf** → typed, direct, fast, picky
* **fgets + sscanf** → safe, full-line, flexible, debuggable

---

## 5️⃣ Examples

### Example 1: Strings + Integer

```c
Input: bhavesh yadav 14
scanf("%s %s %d") → works fine
fgets + sscanf → works fine
```

### Example 2: Type mismatch

```c
Format: %d %d %s
Input: bhavesh yadav 14
→ scanf fails at first token, nothing consumed
→ fgets+sscanf returns 0, safe to handle
```

### Example 3: Mixed order

```c
Format: %d %d %s
Input: 14 14 bhavesh
→ parsed correctly if types match
Input: bhavesh 14 14
→ first token mismatch, parsing stops
```

### Example 4: Multiple words / spaces

* `scanf("%s %s")` → stops at space, leftover remains
* `fgets()` → reads entire line → safer for multi-word strings

---

## 6️⃣ Safe Pattern (Recommended)

```c
char line[100];
char first[20], last[20];
int age;

fgets(line, sizeof(line), stdin);
if (sscanf(line, "%19s %19s %d", first, last, &age) != 3) {
    printf("❌ Invalid input!\n");
} else {
    printf("First=%s, Last=%s, Age=%d\n", first, last, age);
}
```

✅ Advantages:

* Handles spaces, multiple words
* Detects wrong input
* Buffer is clean, no leftover issues
* Prevents overflow with `%19s`

---

## 7️⃣ Mental Rules / Takeaways

1. **scanf** → typed sniper, precise, but picky and buffer-sensitive
2. **fgets + sscanf** → safe bucket → parse carefully
3. Always **check return value** of scanf/sscanf
4. Flush buffer if mixing numeric + string inputs and using scanf
5. **Edge cases** (wrong order, type mismatch, extra words) → fgets + sscanf is safer

---

💡 **Analogy:**

| Tool   | Analogy                                     |
| ------ | ------------------------------------------- |
| stdin  | Kitchen sink (all input flows here)         |
| scanf  | Mug (takes only what format needs)          |
| fgets  | Bucket (takes whole line)                   |
| sscanf | Strainer (filters bucket content by format) |

---

*/
void cleanBuffer(){
    int c;
    while ((c=getchar()) != '\n' && c != EOF){}; //EOF means end of file
}
int main()
{
    char nameBuffer[64];
    int age ;
    char leftOverBuffer[64];

    printf("%s", "Enter your Name and age: ");
    
    scanf("%s", nameBuffer);
    scanf("%d", &age);
    cleanBuffer();
    printf("%s", "Enter your lefoverBuffer: ");

    scanf("%s", leftOverBuffer);

    printf("your Name and age is %s and %d\n", nameBuffer, age);
    printf("lefoverbuffer is %s\n", leftOverBuffer);
    return 0;
}