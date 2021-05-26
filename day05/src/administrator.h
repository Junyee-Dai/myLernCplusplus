#ifndef _ADMINISTRATOR_H_
#define _ADMINISTRATOR_H_

#include "charactor.h"
using namespace std;

class Admin : public Charactor
{
public:
    Admin();
    Admin(int id, string nm, string pwd);
    
    virtual void openMenu();

    //添加账号
    void addAccount();
    //查看账号
    void showAccount();
    //查看机房
    void showRoom();
    //清空预约
    void cleanOrder();
};

#endif
