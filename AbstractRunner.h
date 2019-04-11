/*
    遵循原则：依赖倒转原则，面向接口编程，对主要接口采用模板方法模式进行自定义运动员
    抽象runner类
*/

#ifndef _ABS_RUNNER_
#define _ABS_RUNNER_

#include <iostream>
#include "Common.h"

class AbstractWeapon;

class AbstractRunner
{
public:
    AbstractRunner();
    virtual ~AbstractRunner();
    void Init(double iSpeed, char iName[]);
    void Run(bool &reached, double &nextPosi);
    void Action();
    void PrintName();
    void Report();
    void AddWeapon(AbstractWeapon *iWeapon); // 暂时定义成公有，后续需要移植到Init去调用，每个角色必须佩带

protected: // 不能定义成private，这样子类无法访问
    double step; // 步长
    double curPosi;
    uint totalActionTimes; // 记录行动次数
    uint attackTimes;

private:
    virtual void CustRun(bool &reached, double &nextPosi) = 0;
    virtual void CustAction(double &iCoolDown) = 0;
    virtual void CustInit() = 0;
    // 由于该类有指针，需要禁用复制构造函数和赋值运算符
    AbstractRunner(const AbstractRunner&);
    AbstractRunner& operator=(const AbstractRunner&);

private:
    char *name;
    double speed;
    AbstractWeapon *weapon;
    bool inited; // 是否已经初始化成功
};

#endif
