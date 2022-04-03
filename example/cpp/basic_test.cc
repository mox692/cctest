#include <cctest/cctest.h>
#include "basic.hpp"
// #include <stdio.h>

int main()
{
    Person p1 = Person(3);
    Person p2 = Person(3);
    // EQ("eq", p1, p2);
    ASSERT_INT("", 3, 3);
    return 0;
}
