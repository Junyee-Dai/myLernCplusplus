/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-23 16:12:10
 * @Description: 加号运算符重载
 * 实现两个自定义数据类型相加
*/

#include <iostream>
#include <string>

using namespace std;

// 1、成员函数重载+
class Person
{
// public:
//     Person operator+(Person &p)
//     {
//         Person tmp;
//         tmp.m_A = this->m_A + p.m_A;
//         tmp.m_B = this->m_B + p.m_B;
//         return tmp;
//     }
public:
    int m_A;
    int m_B;
};

//2、全局函数重载+
Person operator+ (Person &p1, Person&p2)
{
    Person tmp;
    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp;
}

//3、运算符重载函数也可以发生重载
Person operator+ (Person &p, int x)
{
    Person tmp;
    tmp.m_A += x;
    tmp.m_B += x;
    return tmp;
}

void test01(){
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    Person p3 = p1 + p2;
    //成员函数调用本质： Person p3 = p1.operator+(p2);
    //全局函数调用本质： Person p3 = operator+(p1, p2);
    Person p4 = p3 + 20;
    //重载
    cout<<"p3: m_A:"<<p3.m_A<<" m_B:"<<p3.m_B<<endl;
    cout<<"p4: m_A:"<<p4.m_A<<" m_B:"<<p4.m_B<<endl;
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}