/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-23 16:58:18
 * @Description: 递增运算符++重载
*/

#include <iostream>
#include <string>

using namespace std;

class MyInt
{
friend ostream& operator<<(ostream& os, MyInt m);
public:
    MyInt(){m_int = 0;}
    //++运算符分为前置++和后置++
    //前置
    MyInt& operator++()
    {
        //先自增，再返回
        m_int++;
        return *this;
    }
    //后置
    MyInt operator++(int) //int 代表占位参数，可以区分前置还是后置递增
    {
        //先返回，后自增
        MyInt tmp = *this;
        m_int++;
        return tmp;
    }
private:
    int m_int;
};

ostream& operator<<(ostream& os, MyInt m)
{
    os << m.m_int << endl;
    return os;
}

void test01(){
    MyInt mi;
    cout << mi << endl; // need overload<<
    cout << ++mi << endl; // need overload++
    cout << mi++ << endl; // need overload++
    cout << mi << endl; // need overload<<
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}