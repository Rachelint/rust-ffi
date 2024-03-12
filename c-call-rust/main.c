#include "bindings.h"

int main(void) {
    call_from_c();
    struct Foo* foo = new_foo();
    say_foo(foo);
    free_foo(foo);
    return 0;
}
