/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-19 17:30:48
 * @Description: 类做友元
*/

#include <iostream>
#include <string>

using namespace std;

class Building;
class Friend
{
public:
    Friend();
    void visit();
private:
    Building *build;
};

class Building
{
    friend class Friend;
public:
    Building(){
        this->m_BedRoom = "BedRoom";
        this->m_SittingRoom = "SittingRoom";
    }
    string m_SittingRoom;
private:
    string m_BedRoom;    
};

Friend::Friend()
{
    this->build = new Building;
}

void Friend::visit()
{
    cout << "Jack try's to visit " << build->m_SittingRoom << endl;
    cout << "Jack try's to visit " << build->m_BedRoom << endl;
}

void test01(){
    Friend frd;
    frd.visit();    
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}