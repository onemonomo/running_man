/*
    遵循原则：依赖倒转原则，面向接口编程，对主要接口采用模板方法模式进行自定义运动员
    抽象runner类
*/

#ifndef _ABS_RUNNER_
#define _ABS_RUNNER_

#include "string.h"
#include "Common.h"

class AbstractRunner
{
public:
    AbstractRunner()
    {
        name = nullptr;
        speed = 0;
        curPosi = 0;
        inited = false;
    }

    // 抽象类析构函数需要虚化
    virtual ~AbstractRunner()
    {
        if(name != nullptr){
            delete [] name;
        }
    }

    void Init(uint iSpeed, char* iName)
    {
        // 空指针保护
        if(iName == nullptr){
            printf("wrong input name.\n");
            return;
        }
        name = new char[sizeof(char)];
        strcpy(name, iName);

        speed = iSpeed;
        // 各个角色自适应初始化
        CustInit();
        printf("%s init succed.\n", name);
        inited = true;
    }
    
    // 不应该用这种方式获取跑道长度，应该player中添加playground的指针 todo 
    void NotifyTrackLen(uint iTrackLen)
    {
        trackLength = iTrackLen;
        return;
    }

    // 对外接口最好固定下来，采用模板方法模式
    void Run()
    {
        // 待定需要什么返回值和入参
        CustRun();
    }

    void PrintName()
    {
        if (name == nullptr){
            printf("name not exist.\n");
            return;
        }
        printf("%s\n", name);
    }

protected: // 不能定义成private，这样子类无法访问--->错,虚函数可以继承重写
    char *name;
    uint speed; // 毫秒速度
    uint curPosi;
    uint trackLength;
    bool inited; // 是否已经初始化成功

private:
    virtual void CustRun() = 0;
    virtual void CustInit() = 0;
    // 由于该类有指针，需要禁用复制构造函数和赋值运算符
    AbstractRunner(const AbstractRunner&);
    AbstractRunner& operator=(const AbstractRunner&);
};

#endif