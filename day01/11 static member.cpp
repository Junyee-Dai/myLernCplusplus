/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-19 15:25:36
 * @Description: 静态成员
 * 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
 * 静态成员分为：
   * *  静态成员变量
   *  所有对象共享同一份数据
   *  在编译阶段分配内存
   *  类内声明，类外初始化
   
   * * 静态成员函数
   *  所有对象共享同一个函数
   *  静态成员函数只能访问静态成员变量
*/
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    //所有对象共享一份数据
    //编译阶段就分配内存
    //类内声明，类外初始化
    static int m_A;
    static int m_B;
private:
    static int m_C;
};
int Person::m_A = 8848;
int Person::m_B = 1234;
int Person::m_C = 4321;

int main(int argc, char *argv[])
{
    Person p1;
    cout<<p1.m_A<<endl;

    Person p2;
    p2.m_A = 4396;
    cout<<p2.m_A<<endl;
    cout<<p1.m_A<<endl; //共享一份数据

    //静态成员不属于某个对象，所有对象共享一份数据
    //静态成员变量有两种访问方式
    //1 通过对象进行访问
    Person p3;
    cout << p3.m_B << endl;
    //2 通过类进行访问
    cout << Person::m_B << endl;

    //3 静态成员也适用于权限
    // cout << Person::m_C << endl;
    return 0;
}