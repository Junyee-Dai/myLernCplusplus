/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 10:54:43
 * @Description: 继承中的对象模型
 * 问题：从父类继承来的成员中，是否都属于子类成员？
*/

#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Derive :public Base
{
public:
	int m_D;
};

void test01(){
    cout << sizeof(Base) << endl;
    cout << sizeof(Derive) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}