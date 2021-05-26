#ifndef _TEACHER_H_
#define _TEACHER_H_

#include "charactor.h"
using namespace std;

class Teacher : public Charactor
{
public:
    Teacher();
    Teacher(int id, string nm, string pwd);
    
    virtual void openMenu();

    //所有预约
    void allOrder();
    //审核预约
    void validOrder();
};

#endif