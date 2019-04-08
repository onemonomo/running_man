#include "AbstractRunner.h"

AbstractRunner::AbstractRunner()
{
    name = nullptr;
    speed = 0;
    curPosi = 0;
    step = 1;
    totalActionTimes = 0;
    inited = false;
}

// 抽象类析构函数需要虚化
AbstractRunner::~AbstractRunner()
{
    if(name != nullptr){
        delete [] name;
        name = nullptr;
    }
}

void AbstractRunner::Init(double iSpeed, char* iName)
{
    // 空指针保护
    if(iName == nullptr){
        printf("wrong input name.\n");
        return;
    }
    name = new char[sizeof(char)];
    strcpy(name, iName);
    // 冷却时间默认4秒
    coolDown = 4.0;
    speed = iSpeed;
    // 各个角色自适应初始化
    CustInit();

    // 初始位置设置
    curPosi = STANDARD_DISTANCE * STANDARD_SPEED/speed;
    printf("%s init succed.\n", name);
    inited = true;
}

// 对外接口最好固定下来，采用模板方法模式
// 跑0.1秒
void AbstractRunner::Run(bool &reached, double &nextPosi)
{
    // 待定需要什么返回值和入参
    curPosi -= step;
    if(curPosi < 0){
        reached = 1;
        return;
    }
    reached = 0;
    return;
    CustRun(reached, nextPosi);
}

void AbstractRunner::Action()
{
    totalActionTimes++;
    printf("%s action %d\n", name, totalActionTimes);

    // 下次位置变更为CD时间x标准长度
    curPosi = coolDown * STANDARD_DISTANCE * STANDARD_SPEED / speed;

    /*
    int cmd;
    scanf("%d", &cmd);
    printf("this is input: %d\n", cmd);
    */
    return;
}

void AbstractRunner::PrintName()
{
    if (name == nullptr){
        printf("name not exist.\n");
        return;
    }
    printf("%s is at %f\n", name, curPosi);
}

void AbstractRunner::Report()
{
    if (name == nullptr){
        printf("name not exist.\n");
        return;
    }
    printf("%s actioned times = %d\n", name, totalActionTimes);
}
