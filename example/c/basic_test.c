#include <cctest/cctest.h>
#include "basic.h"

int main()
{
    CC_TEST_START;
    ASSERT_INT("add test", add(1, 4), 5);
    ASSERT_INT("fib test", fib(8), 23);
    ASSERT_INT("fib test", fib(8), 21);
    ASSERT_NSTR("cmp test", "fdsa", "fdsa", 4);
    ASSERT_STR("cmp test", "fdsa", "fdsa3");
    CC_TEST_END;
}
