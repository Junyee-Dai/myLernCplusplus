/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 14:53:36
 * @Description: 多态
 * 
 * 多态是C++面向对象三大特性之一
 * 多态分为两类
 *   静态多态：
 *      函数重载 运算符重载
 *   动态多态：
 *      派生类和虚函数实现运行时多态
 * 
 * 静态和动态区别：
 *   静态多态函数地址早绑定-->编译阶段分配地址
 *   动态多态函数地址晚绑定-->运行阶段分配地址
 *
*/
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout<<"animal speak"<<endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout<<"dog speak"<<endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout<<"cat speak"<<endl;
    }
};
//传入什么对象，就调用什么对象的方法
void doSpeak(Animal &animal)
{
    animal.speak();
}

//多态满足条件：
//1.有继承关系
//2.派生类重写基类的方法
void test01(){
    Dog dog;
    Cat cat;
    doSpeak(dog);
    doSpeak(cat);
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}