/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-26 14:35:53
 * @Description: main
*/

#include <iostream>
#include <string>
#include <fstream>
#include "charactor.h"
#include "globalfile.h"
#include "student.h"
using namespace std;



void showHomePage(){
    cout << "---Computer Room Reservation System---"<<endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "  |\t1. Student      \t|\t"<< endl;
    cout << endl;
    cout << "  |\t2. Teacher      \t|\t"<< endl;
    cout << endl;
    cout << "  |\t3. Administrator\t|\t"<< endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << endl; 
}

void Login(string fileName, int flag) //flag表身份
{
    Charactor *ch = nullptr;
    string name;
    string pwd;
    int id;

    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if(!ifs.is_open())
    {
        cout << "failed: file not found"<< endl;
        ifs.close();
        return;
    }

    if(flag == 1)
    {
        cout << "plz input student id" << endl;
        cin >> id;
    }
    if(flag == 2)
    {
        cout << "plz input teacher id" << endl;
        cin >> id;
    }
    if(flag == 3)
    {
        cout << "plz input admin id" << endl;
        cin >> id;
    }

    if(!isdigit(id))
    {
        cout << "id is illeagal!" << endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {
        cout << "plz input username" << endl;
        cin >> name;
        cout << "plz input password" << endl;
        cin >> pwd;
    }
    /*
    身份验证
    */
    if(flag == 1)
    {
        int fileID;
        string fileName, filePasswd;
        while (ifs >> fileID && ifs >> fileName && ifs >> filePasswd)
        {
            if(fileID == id && fileName == name && filePasswd == pwd)
            {
                cout << "login seccessed!" << endl;
                system("pause");
                system("cls");
                
                //进入学生界面

                return;
            }
            else
            {
                cout << "failed! id or username or password is wrong!" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
    }
    if(flag == 2)
    {
        int fileID;
        string fileName, filePasswd;
        while (ifs >> fileID && ifs >> fileName && ifs >> filePasswd)
        {
            if(fileID == id && fileName == name && filePasswd == pwd)
            {
                cout << "login seccessed!" << endl;
                system("pause");
                system("cls");
                
                //进入教师界面

                return;
            }
            else
            {
                cout << "failed! id or username or password is wrong!" << endl;
                system("pause");
                system("cls");
                return;
            }
        }
    }

    cout << "login failed" << endl;
    system("pause");
    system("cls");
}


int main(int argc, char *argv[])
{
    int select; //接收用户选择
    while(true)
    {
        showHomePage();
        cout << "choose charactor..." << endl;
        _sleep(10);
        cin >> select;
        switch (select)
        {
        case 1: //学生
            Login(STUDENT_FILE, 1);break;
        case 2: //老师
            Login(TEACHER_FILE, 2);break;
        case 3: //管理员
            Login(ADMIN_FILE, 3);break;
        default:
            cout<<"unleagal input, plz choose again"<<endl;
            system("pause");
            _sleep(10);
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}