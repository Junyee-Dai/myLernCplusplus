/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-23 16:43:07
 * @Description: 左移运算符重载
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    //利用成员函数重载左移运算符
    // void operator<<(cout) //简化版本 p << cout 与预期相反
    // 故一般不适用成员函数重载左移运算符
public:
    int m_A;
    int m_B;
};

//利用全局函数重载左移运算符
ostream& operator<<(ostream &cout, Person &p) //本质 operator<<(cout, p) -->简化 cout << p
{
    cout << "m_A " << p.m_A <<" m_B "<< p.m_B;
    return cout;
}
void test01(){
    Person p;
    p.m_A = 10;
    p.m_B = 10;

    // cout << p; // wrong! 编译器不知道怎么输出
    cout << p; 
    cout << endl;
    // cout << p << endl; //wrong! 重载函数返回为void，不能继续追加链式操作
    //需要继续返回cout
    cout << p << endl;
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}