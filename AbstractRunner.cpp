#include "AbstractRunner.h"
#include "string.h"

AbstractRunner::AbstractRunner()
{
    name = nullptr;
    speed = 0;
    weapon = nullptr;
    curPosi = 0;
    step = 1;
    totalActionTimes = 0;
    attackTimes = 0;
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

void AbstractRunner::Init(double iSpeed, char iName[])
{
    // 空指针保护
    if(iName == nullptr){
        printf("wrong input name.\n");
        return;
    }

    name = new char[strlen(iName)+1];
    strcpy(name, iName);

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

void AbstractRunner::AddWeapon(AbstractWeapon *iWeapon)
{
    if (iWeapon == nullptr){
        printf("null ptr.\n");
        return;
    }
    weapon = iWeapon;
}

void AbstractRunner::Action()
{
    double coolDown = 4.0;
    CustAction(coolDown);
    // ++固定CustAction后面，CustAction依赖totalActionTimes
    totalActionTimes++;
    printf("%s action %d, with coolDown(%.5f)\n", name, totalActionTimes, coolDown);
    // 下次位置变更为CD时间x标准长度
    curPosi += coolDown * STANDARD_DISTANCE * STANDARD_SPEED / speed;

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
    printf("%s actioned_times(%d) attack_times(%d)\n", name, totalActionTimes, attackTimes);
}
