
  

## General rules

  
  

### 1. Do NOT use space between keyword and opening bracket

```c

/* OK */

if(condition)

while(condition)

for(init;condition;step)

do {} while(condition)

  

/* WRONG */

if (condition)

while (condition)

for (init; condition; step)

do {} while (condition)

```

### 2.1 For functions names use [lower Camel case](https://www.techtarget.com/whatis/definition/CamelCase) (if one than 1 word is needed)

```c

void  someFunction(); /* OK */

void  another_function(); /* Wrong */

void  morefunctions(); /* Wrong */

void OneFunction /* Wrong */

```

  

### 2.2 Use only lowercase characters for variables with optional underscore `_` char

```c

int some_variable; /* OK */

double otherVariable; /* Wrong */

```

  
  

### 3. Do not use space between function name and opening bracket

```c

int32_t a = sum(4, 3); /* OK */

int32_t a = sum (4, 3); /* Wrong */

```

  

### 4. Opening curly bracket is always at the next line from keyword (`for`, `while`, `do`, `switch`, `if`, ...)

```c

int i;

for (i = 0; i < 5; ++i) /* OK */

{

}

for (i = 0; i < 5; ++i) { /* Wrong */

}

for (i = 0; i < 5; ++i){ /* Wrong */

}

```

  

### 5. Use single space after every comma

```c

funcName(5, 4); /* OK */

funcName(4,3); /* Wrong */

```

  

### 6.1 Declare all local variables of the same type in the same line

```c

my_func(){

/* 1 */

char a; /* OK */

/* 2 */

char a, b; /* OK */

/* 3 */

char a;

char b; /* Wrong, variable with char type already exists */

}

```

### 6.2 Declare counter variables in `for` loop

```c

/* OK */

for(int i = 0; i < 10; ++i)

  

/* OK, if you need counter variable later */

int i;

for(i = 0; i < 10; ++i){

if (...){

break;

}

}

if(i == 10){

  

}

  

/* Wrong */

int i;

for(i = 0; i < 10; ++i) ...

```

  

### 7.  Always compare pointers against `NULL` value

```c

void* ptr;

  

/* ... */

  

/* OK, compare against NULL */

if(ptr == NULL || ptr != NULL){

  

}

  

/* Wrong */

if(ptr || !ptr){

  

}

```

  

### 8.  Always respect code style already used in project or library