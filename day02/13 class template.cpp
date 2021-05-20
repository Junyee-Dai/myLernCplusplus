#include <iostream>
#include <string>

using namespace std;

template<typename NameType, typename AgeType> 
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test01(){
    // 指定NameType 为string类型，AgeType 为 int类型
	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();

    Person<int, string>P2(8848, "4396");
	P2.showPerson();
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}