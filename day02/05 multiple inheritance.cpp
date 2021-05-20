#include <iostream>
#include <string>

using namespace std;

class Base1 {
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};
class Base2 {
public:
	Base2()
	{
		m_B = 200; 
	}
public:
	int m_B;
};
class Base3 {
public:
	Base3()
	{
		m_A = 200;  
	}
public:
	int m_A;
};

class Derive : public Base1, public Base2
{
    public:
    Derive(){
        m_C = 300;
    }
    int m_C;
};
void test01(){
    Derive de;
    cout << sizeof(de) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}