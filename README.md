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

# Example

# Installing

Once you've [built and installed](https://github.com/eudoxia0/cmacro#installing)
cmacro, simply put these files in a directory where they can be included by
cmacro.

# Functions

## Anonymous Functions

**File:** `fn/lambda.c`

**Examples**:

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

# Anaphoric Macros

## `if`

**File:** `anaphoric/if.c`

**Examples**:

```c
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

**Examples**:

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
