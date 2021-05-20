/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 16:24:22
 * @Description: 模板函数示例
*/

#include <iostream>
#include <string>

using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    double a = 1.0;
    double b = 2.0;

    cout << "a = "<<a<<" ,b = "<<b<<endl;
    mySwap(a, b);
    cout << "a = "<<a<<" ,b = "<<b<<endl;
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}