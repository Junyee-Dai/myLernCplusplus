/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 16:31:54
 * @Description: 普通函数与函数模板的区别
 * **普通函数与函数模板区别：**

* 普通函数调用时可以发生自动类型转换（隐式类型转换）
* 函数模板调用时，如果利用"自动"类型推导，不会发生隐式类型转换
* 如果利用"显示"指定类型的方式，可以发生隐式类型转换
*/
#include <iostream>
#include <string>

using namespace std;

//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myAdd02(T a, T b)  
{
	return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	
	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型  'c' 对应 ASCII码 99

	//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换

	//myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl; 
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}