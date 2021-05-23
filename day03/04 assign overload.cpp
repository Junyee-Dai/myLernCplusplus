/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-23 17:23:33
 * @Description: 赋值运算符重载
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->m_Age = new int(age);
    }
    ~Person()
    {
        if(m_Age != nullptr)
        {
            delete m_Age;
            m_Age = nullptr;
        }
    }
    //重载浅拷贝赋值为深拷贝赋值
    Person& operator=(Person &p)
    {
        //先判断是否有属性在堆区，如果有则释放
        if(this->m_Age != nullptr)
        {
            delete m_Age;
            m_Age = nullptr;
        }

        //释放完成后进行深拷贝，注意新开辟一块内存
        m_Age = new int(*p.m_Age); //使用p的m_age，
        //因为是在堆区，所以解引用得到m_Age本身的值，再用这个值new给this
        return *this;
    }

    int *m_Age;
};

void test01(){
    Person p1(18);
    Person p2(20);

    // p1 = p2; //异常 
    //编译器提供的赋值浅拷贝
    //析构的时候同一块内存被重复释放
    //需要深拷贝，可以重载赋值操作符= 来完成

    //深拷贝赋值(重载后的=)
    p1 = p2;

    cout << "p1 age "<< *p1.m_Age << endl;
    cout << "p2 age "<< *p2.m_Age << endl;
    
    //连续赋值
    Person p3(30);
    p1 = p2 = p3; //需要修改赋值重载的返回值
    cout << "p1 age "<< *p1.m_Age << endl;
    cout << "p2 age "<< *p1.m_Age << endl;
    cout << "p3 age "<< *p2.m_Age << endl;
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}