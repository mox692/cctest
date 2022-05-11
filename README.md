<img width="200" alt="スクリーンショット 2022-05-12 0 49 05" src="https://user-images.githubusercontent.com/55653825/167892863-d80f9525-0fce-4090-8b55-e71092ee0865.png">

A light weight test utils for C, C++.

# Feature
* simple assertion for each primitive type (C, C++)
* simple `EQ` macro using the definition of the = operator for that class.

# Install
```
$ make install
```

# Getting started 

## C
sample code
```c
#include <cctest/cctest.h>

int add(int a, int b)
{
    return a + b;
}
int fib(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    CC_TEST_START;
    ASSERT_INT("add test", add(1, 4), 5);
    ASSERT_INT("fib test", fib(8), 21);
    CC_TEST_END;
}
```

build & run
```bash
$ gcc -c -o basic_test.o basic_test.c
$ gcc -o basic_test basic_test.o
$ ./basic_test
==== Test Start ===
-- TEST: add test ... ok✅
-- TEST: fib test ... ok✅
==== All Test Passed 🎉===
```

## C++

basic.hpp
```cpp
#include <string.h>
#include <iostream>

class Person
{
public:
    Person(int age) : age(age){};
    int age;

private:
};

// 
// To use EQ macro, you should implement `<<` and `==` operator for your class.
// 
inline std::ostream &operator<<(std::ostream &os, const Person &p)
{
    std::cout << age: << p.age;
    return os;
}

inline bool operator==(const Person &lhs, const Person &rhs) { return lhs.age == rhs.age; }
```

basic_test.cc
```cpp
#include <iostream>
#include <string>
#include "basic.hpp"
#include <cctest/cctest.h>

int main()
{
    CC_TEST_START;
    Person p1 = Person(3);
    Person p2 = Person(3);
    EQ("person should equal.", p1, p2);
    CC_TEST_END;
    return 0;
}

```

build & run
```bash
$ g++ -c -o basic.o basic.cc
$ g++ -o basic_test basic_test.o
$ ./basic_test
==== Test Start ===
-- TEST: person should equal. ... ok✅
==== All Test Passed 🎉===
```

See the example dir for detail.
