/*
 * @Author: Junyi Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 10:00:53
 * @Description: 继承的基本语法
 * 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同

接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处
*/
#include <iostream>
#include <string>

using namespace std;

class BasePage
{
public:
    static void show(){
        header();
        footer();
    }
private:
    static void header();
    static void footer();
};
void BasePage::header(){
    cout << "HomePage\tPublic\tlogin" << endl;
}
void BasePage::footer(){
    cout << "About\tHellp\tcooperation" << endl;
}

class CplusplusPage : public BasePage
{
    public:
    void content(){
        cout<<"C++"<<endl;
    }
};

class PythonPage : public BasePage
{
    public:
    void content(){
        cout<<"Python"<<endl;
    }
};
void test01(){
    CplusplusPage c;
    PythonPage p;
    p.content();
    c.content();
    BasePage::show();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}