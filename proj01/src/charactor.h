/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-26 15:04:59
 * @Description: 角色抽象类
*/

#ifndef _CHARACTOR_H_
#define _CHARACTOR_H_

#include <iostream>
#include <string>

using namespace std;

class Charactor{
public:
    virtual void openMenu() = 0;

    string m_Username;
    string m_Passwd;
    int m_ID;
};

#endif