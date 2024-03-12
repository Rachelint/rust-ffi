#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Foo {
  int a;
  char *b;
} Foo;

void call_from_c(void);

struct Foo *new_foo(void);

void free_foo(struct Foo *foo);

void say_foo(struct Foo *foo);
