/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-19 14:39:02
 * @Description: 深拷贝与浅拷贝


** 深浅拷贝是面试经典问题，也是常见的一个坑

** 浅拷贝：简单的赋值拷贝操作

** 深拷贝：在堆区重新申请空间，进行拷贝操作

总结：  如果属性有在堆区开辟的，
        一定要自己提供拷贝构造函数，
        防止浅拷贝带来的问题
*/

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    int m_Age;
    int* m_Height;
public:
    Person(){cout<<"default ctor"<<endl;}
    Person(int age, int height){
        cout<<"Args ctor"<<endl;
        m_Age = age;
        m_Height = new int(height);
    }
    Person(const Person & p)
    {
        cout<<"copy ctor"<<endl;
        this->m_Age = p.m_Age;
        this->m_Height = new int(*p.m_Height);
    }
    ~Person(){
        if(m_Height != nullptr){
            delete m_Height;
            m_Height = nullptr;
        }
        cout<<"dtor"<<endl;
    }
};
void test01()
{
	Person p1(18, 180);

	Person p2(p1);

	cout << "p1的年龄： " << p1.m_Age << " 身高： " << *p1.m_Height << endl;

	cout << "p2的年龄： " << p2.m_Age << " 身高： " << *p2.m_Height << endl;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}