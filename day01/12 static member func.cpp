#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    //静态成员函数访问变量
    static void haha()
    {
        cout << "hha" << endl;
        cout << m_A << endl;
        // cout << m_B << endl; 静态成员函数只能访问静态成员变量
    }
public:
    static int m_A;
    int m_B = 100;
};

int Person::m_A = 100;

//两种访问方式
void test01()
{
    //1.通过对象访问
    Person p;
    p.haha();
    
    //2.通过类名访问
    Person::haha();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}