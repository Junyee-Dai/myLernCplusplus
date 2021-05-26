/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-26 15:16:44
 * @Description: 学生类实现
*/

#include "student.h"
using namespace std;

Student::Student(){}
Student::Student(int id, string nm, string pwd){
    this->m_ID = id;
    this->m_Username = nm;
    this->m_Passwd = pwd;
}

void Student::openMenu(){}

//申请预约
void Student::applyOrder(){}
//查看预约
void Student::showOrder(){}
//所有预约
void Student::allOrder(){}
//取消预约
void Student::cancelOrder(){}

