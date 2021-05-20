/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 14:12:34
 * @Description: 菱形继承
 * 
 * 菱形继承概念：
 * 两个派生类继承同一个基类
 * 某个类又同时继承两个派生类
 * 这种继承被称为菱形继承或钻石继承
*/

#include <iostream>
#include <string>

using namespace std;

/*
1.  羊继承了动物的数据，驼同样继承了动物的数据，
    当羊驼使用数据时，就会产生二义性。

2.  羊驼继承自动物的数据继承了两份，
    其实这份数据我们只需要一份就可以。
*/
class Animal{
public:
    int m_Age;
};

class Yang : virtual public Animal{};
class Tuo : virtual public Animal{};

class Yangtuo : public Yang, public Tuo{};

void test01(){
    Yangtuo yt;
    yt.Yang::m_Age = 18;
    yt.Tuo::m_Age = 19;
    //菱形继承，两个父类有相同字段，需要加作用域加以区分
    cout << yt.Yang::m_Age << endl;
    cout << yt.Tuo::m_Age << endl;
    //但是年龄只要一份就行了，没有实际解决问题
    //利用虚继承解决菱形继承的问题
    //在继承：后加上virtual变为虚继承
    //此时Animal类为虚基类
    //此时m_Age只剩一份了，18会被19覆盖
    //yt.m_Age也可以直接使用，不用加作用域，没有二义性
    cout << yt.m_Age << endl;
    cout << sizeof(yt) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}