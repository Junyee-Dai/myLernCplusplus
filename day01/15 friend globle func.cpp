/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-19 16:56:38
 * @Description: 全局函数做友元
*/

#include <iostream>
#include <string>

using namespace std;

class Building
{
    friend void visit(Building *build);
public:
    Building(){
        this->m_SittingRoom="SittingRoom";
        this->m_BedRoom="BedRoom";
    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

void visit(Building *build)
{
    cout << "Jack try's to visit " << build->m_SittingRoom << endl;
    cout << "Jack try's to visit " << build->m_BedRoom << endl;
}

void test01()
{
    Building bu;
    visit(&bu);
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}