/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 10:59:27
 * @Description: 继承中构造和析构顺序
*/

#include <iostream>
#include <string>

using namespace std;

class Base 
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base()
	{
		cout << "Base析构函数!" << endl;
	}
};
class Derive : public Base
{
public:
	Derive()
	{
		cout << "Derive构造函数!" << endl;
	}
	~Derive()
	{
		cout << "Derive析构函数!" << endl;
	}

};
void test01(){
    Derive de;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}

