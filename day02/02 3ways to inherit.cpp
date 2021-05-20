/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 10:19:15
 * @Description: 继承方式
 * 
 * 继承的三种方式
 *  public继承 
 *  protected继承
 *  private继承
*/

#include <iostream>
#include <string>

using namespace std;

class Base{
public:
    int m_Public;
protected:
    int m_Protect;
private:
    int m_Private;
};

// public inherit
class Derive01 : public Base{
public:
    void access(){
        m_Public; // ok
        m_Protect; // ok
        // m_Private; // wrong!!
    }
};
void test01(){
    Derive01 de;
    de.m_Public; 
    // de.m_Protect; // wrong!!
}

// protected inherit
class Derive02 : protected Base{
public:
    void access(){
        m_Public; // ok
        m_Protect; // ok
        // m_Private; // wrong!!
    }
};
void test02(){
    Derive02 de;
    // de.m_Public; // wrong!! public --> protected
}

// privated inherit
class Derive03 : private Base{
public:
    void access(){
        m_Public; // ok
        m_Protect; // ok
        // m_Private; // wrong!! 
        //结论： 基类中的privite无论以何种形式继承都不能访问
    }
};
void test03(){
    Derive03 de;
    // de.m_Public; // wrong!! public --> private
}

int main(int argc, char *argv[])
{
    return 0;
}