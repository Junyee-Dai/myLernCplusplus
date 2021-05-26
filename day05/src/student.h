/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-26 15:09:22
 * @Description: 学生类
*/
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "charactor.h"
using namespace std;

class Student : public Charactor
{
public:
    Student();
    Student(int id, string nm, string pwd);
    
    virtual void openMenu();

    //申请预约
    void applyOrder();
    //查看预约
    void showOrder();
    //所有预约
    void allOrder();
    //取消预约
    void cancelOrder();
};

#endif