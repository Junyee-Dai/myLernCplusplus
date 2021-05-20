/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 15:13:54
 * @Description: 纯虚函数和抽象类
 * 
 * 在多态中，通常基类中的虚函数的实现没有意义，
 * 因为派生类会重写方法
 * 因此可以将虚函数改写为“纯虚函数”
 * 
 * 当类中有纯虚函数时，这个类称为“抽象类”
 * 
 * 抽象类特征：
 * 1.无法实例化对象
 * 2.子类必须重写抽象类中的纯虚函数
 * 3.如果没有重写，则子类也是抽象类
*/

#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    virtual void func() = 0; //纯虚函数
};

class Derive : public Base
{
public:
    virtual void func(){
        cout << "hello world" << endl;
    }
};

void test01(){
    // Base bs; // 错误！抽象类无法实例化一个对象
    Derive dr; // 正确！ 派生类重写了所有纯虚函数
    dr.func();

    Base *bsptr = new Derive;  //多态
    bsptr->func();
    delete bsptr;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}