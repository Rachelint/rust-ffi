#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct Foo {
  int a;
  char *b;
};

extern "C" {

void call_from_c();

Foo *new_foo();

void free_foo(Foo *foo);

void say_foo(Foo *foo);

} // extern "C"
