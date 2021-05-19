/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-18 16:34:36
 * @Description: 设计一个圆类，求它的周长
*/

#include <iostream>
#include <string>

using namespace std;

const double pi = 3.14159;

class Circle
{
public:
    double m_R;
    double getPerimeter();
};

double Circle::getPerimeter()
{
    return m_R*2*pi;
}

int main(int argc, char *argv[])
{
    Circle cr1;
    cr1.m_R = 3.0;
    cout<<cr1.getPerimeter()<<endl;
    return 0;
}