#include <string.h>
#include <iostream>

class Person
{
public:
    Person(int age) : age(age){};
    int age;

private:
};
inline std::ostream &operator<<(std::ostream &os, const Person &p)
{
    // print here
    printf("age: %d", p.age);
    return os;
}
inline bool operator==(const Person &lhs, const Person &rhs) { return lhs.age == rhs.age; }
