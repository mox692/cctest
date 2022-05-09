#include <string.h>
#include <iostream>

class Person
{
public:
    Person(int age) : age(age){};
    int age;

    static bool eq(const Person p1, const Person p2)
    {
        if (p1.age != p2.age)
        {
            return false;
        }
        return true;
    }

private:
};
inline std::ostream &operator<<(std::ostream &os, const Person &p)
{
    // print here
    printf("age: %d", p.age);
    return os;
}
