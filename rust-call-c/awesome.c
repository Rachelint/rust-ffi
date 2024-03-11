#include <stdio.h>
#include "awesome.h"

void say_foo(Foo foo) {
  printf("Foo { a = %d, b = %s}\n", foo.a, foo.b);
}

void rust_call_c() {
  printf("Just called a C function from Rust!\n");
}
