#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
    cout << "ctor called ..." <<endl;
}

Person::~Person()
{
    cout << "dtor called ..." <<endl;

}

int main(int argc, char *argv[])
{
    Person p;
    return 0;
}