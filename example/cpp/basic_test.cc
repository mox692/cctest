#include <cctest/cctest.h>
#include "basic.hpp"
#include <stdio.h>

int main()
{
    Person p1 = Person(3);
    Person p2 = Person(3);
    if (eq(p1, p2))
    {
        printf("same\n");
    }
    else
    {
        printf("not same\n");
    }
    return 0;
}
