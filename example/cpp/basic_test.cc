#include <iostream>
#include <string>
#include "basic.hpp"
#include <cctest/cctest.h>

int main()
{
    CC_TEST_START;
    Person p1 = Person(3);
    Person p2 = Person(3);
    EQ("eq", p1, p2);
    ASSERT_STR("bbbb", "aaaa", "aaaa");
    CC_TEST_END;
    return 0;
}
