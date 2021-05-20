/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-19 14:56:34
 * @Description: 构造函数调用规则
 * 
 * 1.创建一个类，C++编译器会给每个类添加
 * 构造函数
 * 析构函数
 * 拷贝构造
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
    int m_Age;
    public:
    Person(){cout << "defalut ctor called"<<endl;}  
    ~Person(){cout << "dtor called"<<endl;}
    Person(int age){
        cout << "args ctor called"<<endl;
        this->m_Age = age;
    }
    // Person(const Person &p){
    //     cout << "copy ctor called"<<endl;
    //     this->m_Age = p.m_Age;
    // }
};

void test01()
{
    Person p;
    p.m_Age = 18;

    Person newp(p);
    cout << newp.m_Age << endl;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}

/*
    总结
    如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
    如果用户提供拷贝构造，编译器不会提供其他构造函数
*/