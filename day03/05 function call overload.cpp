/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-23 18:36:57
 * @Description: 函数调用运算符()重载-->仿函数
*/
#include <iostream>
#include <string>

using namespace std;

class MyPrint
{
public:
    void operator()(string str)
    {
        cout << str << endl;
    }
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test01(){
    MyPrint mp;
    mp("hello world");
    cout << MyAdd()(10,20) << endl;
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}