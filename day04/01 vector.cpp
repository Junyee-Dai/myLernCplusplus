/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-24 11:14:00
 * @Description: vector容器
 * 
 * vector结构和数组非常相似，也成为单端数组
 * 
 * vector与普通数据的区别
 * 数组是静态空间，vector“动态扩展”
 * 
 * 动态扩展：
 * “不是”在原有空间后面拼接新空间，而是“另找一块更大的空间”，
 * 并将原数据拷贝到新空间，释放原空间
*/

/*
   -------------------------------------
   |  | | | …… | |            | |    ←push_back
   ------------------------------------- ->pop_back
 ↑     ↑        ↑              ↑   ↑
 |    begin  insert            |  end
rend                         rbegin


    支持随机访问 [i]  .at(i)
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/*
ctor
* `vector<T> v; `               	//采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());      //将v[begin(), end())区间中的元素拷贝给本身。
* `vector(n, elem);`               //构造函数将n个elem拷贝给本身。
* `vector(const vector &vec);`     //拷贝构造函数。
*/
void test01(){
    vector<int> vec1;  //1 默认构造

    for(int i = 0; i < 10; i++)
        vec1.push_back(i+1);

    vector<int> vec2(vec1.begin(), vec1.end());

    printVector(vec1);
    printVector(vec2);
}

/*
assign
* `vector& operator=(const vector &vec);`//重载等号操作符
* `assign(beg, end);`       //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`        //将n个elem拷贝赋值给本身。
*/

void test02()
{
    vector<int> vec1 = {1, 2, 3, 4, 5};
    printVector(vec1);

    vector<int> vec2 = vec1; //operator=
    printVector(vec2);
    
    vector<int> vec3;
    vec3.assign(vec2.begin(), vec2.end()); //assign(begin, end)
    printVector(vec3);

    vector<int> vec4;
    vec4.assign(5, 0);
    printVector(vec4);
}


//capacity & size
/*
* `empty(); `             //判断容器是否为空
* `capacity();`           //容器的容量
* `size();`               //返回容器中元素的个数
* `resize(int num);`      //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					       //如果容器变短，则末尾超出容器长度的元素被删除。
* `resize(int num, elem);` //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				             //如果容器变短，则末尾超出容器长度的元素被删除
*/
void test03()
{
    vector<int> vec1({1, 2, 3, 4, 5});
    printVector(vec1);

    if(vec1.empty()){
        cout<<"vec1 is empty"<<endl;
    }
    else{
        cout<<"vec1's size = "<<vec1.size()<<endl;
        cout<<"vec1's capacity = "<<vec1.capacity()<<endl;
    }

    cout << "-----------" << endl;
    vec1.resize(3);
    printVector(vec1);
    cout << "-----------" << endl;
    vec1.resize(10, 0);
    printVector(vec1);
}

/*
* `push_back(ele);`                      //尾部插入元素ele
* `pop_back();`                          //删除最后一个元素
* `insert(const_iterator pos, ele);`     //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele
* `erase(const_iterator pos);`           //删除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
* `clear();`      
*/
void test04()
{
    vector<int> vec1 = {1, 2, 3, 4};
    printVector(vec1);

    vec1.push_back(5);
    vec1.push_back(6);
    printVector(vec1);

    vec1.pop_back();
    vec1.pop_back();
    printVector(vec1);

    vec1.insert(vec1.begin(), 3, 0);
    printVector(vec1);
    vec1.erase(vec1.begin());
    printVector(vec1);

    vec1.clear();
    printVector(vec1);
}

//`swap(vec);`  // 将vec与本身的元素互换
void test05()
{
    vector<int> vec1 = {1,2,3,4,5};
    printVector(vec1);

    vector<int> vec2 = {5,4,3,2,1};
    printVector(vec2);

    cout<<"------------"<<endl;

    vec1.swap(vec2);
    printVector(vec1);
    printVector(vec2);
}
void test06()
{
    vector<int> vec1;
    for(int i = 0; i < 1000; i++)
    {
        vec1.push_back(i+1);
    }
	cout << "vec1的容量为：" << vec1.capacity() << endl;
	cout << "vec1的大小为：" << vec1.size() << endl;
    
    cout<<"------------"<<endl;
    
    //改变元素个数，但容量没变
    vec1.resize(5);
    cout << "vec1的容量为：" << vec1.capacity() << endl;
	cout << "vec1的大小为：" << vec1.size() << endl;
    
    cout<<"------------"<<endl;

    //收缩内存容量
    // vector<int> v = vec1; //使用vec1为模板构造v，此时v的容量大小为改变后的5
    // cout << "v的容量为：" << v.capacity() << endl;
	// cout << "v的大小为：" << v.size() << endl;
    // v.swap(vec1);   //交换v与vec1

    // 收缩内存容量
    // 直接写为匿名对象形式
    vector<int>(vec1).swap(vec1);
    cout << "vec1的容量为：" << vec1.capacity() << endl;
	cout << "vec1的大小为：" << vec1.size() << endl;
}

int main(int argc, char *argv[])
{
    test06();
    return 0;
}