/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 15:31:01
 * @Description: 多态案例
 * 
 * 案例描述：
 * 制作音频的大致流程为
 * 烧水--> 冲泡 --> 装杯 --> 加料
 * 
 * 利用多态实现本案例，提供抽象饮品基类，
 * 派生类制作咖啡 茶水
*/

#include <iostream>
#include <string>

using namespace std;

class DrinkCraft
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void Pour() = 0;
    virtual void Miix() = 0;
public:
    void doMake()
    {
        Boil();
        Brew();
        Pour();
        Miix();
    }
};
//make Coffee
class Coffee : public DrinkCraft
{
public:
    virtual void Boil(){
        cout << "Coffee Water" << endl;
    }
    virtual void Brew(){
        cout << "Brew Coffee" << endl;
    }
    virtual void Pour(){
        cout << "Pour Coffee" << endl;
    }
     virtual void Miix(){
        cout << "Miix Milk" << endl;
    }
};
//make Tea
class Tea : public DrinkCraft
{
public:
    virtual void Boil(){
        cout << "Tea Water" << endl;
    }
    virtual void Brew(){
        cout << "Brew Tea" << endl;
    }
    virtual void Pour(){
        cout << "Pour Tea" << endl;
    }
     virtual void Miix(){
        cout << "Miix Sugar" << endl;
    }
};

void makeDrink(DrinkCraft *dc)
{
    dc->doMake();
}

void test01(){
    Coffee cf;
    makeDrink(&cf);
    cout << "-------" << endl;
    Tea tea;
    makeDrink(&tea);
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}