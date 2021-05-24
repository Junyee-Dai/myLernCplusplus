/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-24 17:22:05
 * @Description: string容器
 *
string和char * 区别：
* char * 是一个指针
* string是一个类，类内部封装了char *，是一个char*型的容器。

特点：
string 类内部封装了很多成员方法
例如：查找find，拷贝copy，删除delete 替换replace，插入insert
string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责
*/

#include <iostream>
#include <string>

using namespace std;

/*
构造函数原型：

* `string();`          			//创建一个空的字符串 例如: string str;
  `string(const char* s);`	    //使用字符串s初始化
* `string(const string& str);`  //使用一个string对象初始化另一个string对象
* `string(int n, char c);`      //使用n个字符c初始化 
*/
void test01(){
    const char* str = "hello world";
    string s1(str);
    cout << s1 << endl;

    string s2(11,'s');
    cout << s2 << endl;

    string s3("↑↑↑↑↓↓↓↓BABA");
    cout << s3 << endl;
}
/*
* `string& operator+=(const char* str);`           //重载+=操作符
* `string& operator+=(const char c);`              //重载+=操作符
* `string& operator+=(const string& str);`         //重载+=操作符
* `string& append(const char *s); `                //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`          //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`               //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test02(){
    string str1 = "hello";
    string str2(" world");
    string str3 = str1 + str2;
    cout << str3 << endl;
    
    str3.append(" 11223347");
    cout << str3 << endl;

    str3+="89";
    cout << str3 << endl;

    str3.append(str1, 0, 2);
    cout << str3 << endl;
}
int main(int argc, char *argv[])
{
    test02();

    return 0;
}