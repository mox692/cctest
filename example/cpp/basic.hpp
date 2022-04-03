#include <string.h>

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
