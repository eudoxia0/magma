# Magma: [cmacro](https://github.com/eudoxia0/cmacro) extensions to C

# Overview

C is a tremendously useful language: It compiles everywhere, is generally fast,
has a very long history and a stable standard, and comes with few bedrock
abstractions.

Higher-level languages, like Common Lisp and Haskell, provide excellent
metaprogramming systems and a very expressive type system, but have the cost of
various bedrock abstractions like garbage collection, dynamic typing (In the
case of Lisp), and exception handling.

cmacro provides a middleground: It bridges the power and control of C with the
high-level metaprogramming systems of Lisp. This library uses cmacro to extend
the capabilities of the C language.

# Usage

Once you've [built and installed](https://github.com/eudoxia0/cmacro#installing)
cmacro, simply put these files in a directory where they can be included by
cmacro.

# Functions

## Anonymous Functions

**File:** `fn/lambda.c`

**Examples:**

```c
int main() {
  int array[] = {423, 61, 957, 133, 969,
                 829, 821, 390, 704, 596};
  
  qsort(array, 10, sizeof(int),
        lambda (const void* a, const void* b) -> int
        { return *(int*)a - *(int*)b; });
  for(size_t i = 0; i < 10; i++){
    printf("%i ", array[i]);
  }
  return 0;
}
```

# Type System

## Type-Inferenced Variables

**File:** `type/var.c`

**Examples:**

```c
/* Input */
var a = 10;
var b = 3.14;

/* Output */
typeof(10) a = 10;
typeof(3.14) b = 3.14;
/* The above is, in fact, valid */
```

## Algebraic Data Types

**File:** `type/adt.c`

**Examples:**

```c
#include <stdio.h>

data Token {
  Integer { int i; };
  String  { char* str; };
}

int main() {
  Token a, b;
  construct(a, Token -> Integer) { 10 };
  construct(b, Token -> String) { "test" };
  switch(a.type) {
    case TokenInteger:
      return a.Integer.i;
      break;
    case TokenString:
      puts(b.String.str);
      break;
  }
}
```

## Tuples

**File:** `type/tuple.c`

**Examples:**

```c
/* Input */
typedef tup(int, int) pair;

pair divrem(int n, int d) {
  return (pair){n/d, n%d};
}

/* Output */
typedef struct { int first; int second; } pair;

pair divrem(int n, int d) {
  return (pair){n/d, n%d};
}
```

## Anaphoric Macros

## `if`

**File:** `anaphoric/if.c`

**Examples:**

```c
/* Input */
int main() {
  aif (5 > 1)
    return it;
}


/* Output */
int main() {
  aif (5 > 1)
    return it;
}
```

# Utilities

## `doto`

**File:** `util/doto.c`

**Examples:**

```c
/* Input */
void cancelAccount(Account* account) {
  doto(account) {
    setBalance(0);
    setStatus(DISABLED);
  }
}

/* Output */
void cancelAccount(Account* account) {
  setBalance(account, 0);
  setStatus(account, DISABLED);
}
```

## `with_allocation`

**File:** `util/with_allocation.c`

**Examples:**

```c
int main() {
  with_allocation(ptr, int, 10) {
    size_t i;
    for(i = 0; i < 10; i++) {
      ptr[i] = i*2;
    }
  }
  with_allocation(p, int) {
    *p = 10;
    return *p;
  }
}
```

## `with_open_file`

**File:** `util/with_open_file.c`

**Examples:**

```c
int main() {
  with_open_file(file, "README.md", "r") {
    printf("The first character in the README is: %c\n",
           fgetc(file));
  }
  return 0;
}
```

# License

Copyright (c) 2014 Fernando Borretti (eudoxiahp@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
