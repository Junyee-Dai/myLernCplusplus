/*
 * @Author: Junyee-Dai
 * @E-Mail: lyn961103@foxmail.com
 * @Date: 2021-05-20 15:54:57
 * @Description: 多态案例
 * 
 * **案例描述：**



电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）

将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商

创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

测试时组装三台不同的电脑进行工作
*/
#include <iostream>
#include <string>

using namespace std;

class CPU
{
public:
    virtual void calc() = 0;
};

class GPU
{
public:
    virtual void display() = 0;
};

class MEM
{
public:
    virtual void store() = 0;
};

class PC
{
private:
    CPU *m_Cpu;
    GPU *m_Gpu;
    MEM *m_Mem;
public:
    PC(CPU *c, GPU *g, MEM *m)
    {
        this->m_Cpu = c;
        this->m_Gpu = g;
        this->m_Mem = m;
    }
    ~PC()
    {
        if(m_Cpu != nullptr)
        {
            delete m_Cpu;
            m_Cpu = nullptr;
        }
        if(m_Gpu != nullptr)
        {
            delete m_Gpu;
            m_Gpu = nullptr;
        }
        if(m_Mem != nullptr)
        {
            delete m_Mem;
            m_Mem = nullptr;
        }
    }
    void run()
    {
        m_Cpu->calc();
        m_Gpu->display();
        m_Mem->store();
    }
};

class IntelCPU : public CPU
{
public:
    virtual void calc(){
        cout << "intel cpu run" << endl;
    }
};
class AMDCPU : public CPU
{
public:
    virtual void calc(){
        cout << "amd cpu run" << endl;
    }
};

class IntelGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "intel GPU run" << endl;
	}
};
class AMDGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "amd GPU run" << endl;
	}
};

class IntelMem :public MEM
{
public:
	virtual void store()
	{
		cout << "intel Mem run！" << endl;
	}
};
class AMDMem :public MEM
{
public:
	virtual void store()
	{
		cout << "amd Mem run！" << endl;
	}
};
void test01(){
    //PC no.1
    CPU *cpu1 = new IntelCPU;
    GPU *gpu1 = new IntelGPU;
    MEM *mem1 = new IntelMem;

    PC *pc1 = new PC(cpu1, gpu1, mem1);
    pc1->run();
    delete pc1;
    cout << "--------" << endl;
    //PC no.2
    CPU *cpu2 = new AMDCPU;
    GPU *gpu2 = new AMDGPU;
    MEM *mem2 = new AMDMem;

    PC *pc2 = new PC(cpu2, gpu2, mem2);
    pc2->run();
    delete pc2;
    cout << "--------" << endl;
    
    //PC no.3
    PC *pc3 = new PC(new IntelCPU, new AMDGPU, new IntelMem);
    pc3->run();
    delete pc3;

}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}