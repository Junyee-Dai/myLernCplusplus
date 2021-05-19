/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-19 16:26:26
 * @Description: const修饰成员函数
 *
 **常函数：**

* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数
*/

#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(){m_A = 99;m_B=88;}
    void showPerson() const
    {
        m_A = 100;
        cout << m_A << endl;
    }
    void func(){}
public:
    mutable int m_A;
    int m_B;
};

//常对象
void test02()
{
    const Person p;
    p.showPerson();
    //常对象只能调用常函数，不能调用普通函数
    // p.func();
}

int main(int argc, char *argv[])
{
    Person p;
    p.showPerson();
    test02();
    return 0;
}