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
    printf("age: %d", p.age);
    return os;
}

inline bool operator==(const Person &lhs, const Person &rhs) { return lhs.age == rhs.age; }
