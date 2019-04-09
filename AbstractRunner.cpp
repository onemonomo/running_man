#include "AbstractRunner.h"
#include "string.h"

AbstractRunner::AbstractRunner()
{
    name = nullptr;
    speed = 0;
    curPosi = 0;
    step = 1;
    totalActionTimes = 0;
    attackTimes = 0;
    inited = false;
}

// ����������������Ҫ�黯
AbstractRunner::~AbstractRunner()
{
    if(name != nullptr){
        delete [] name;
        name = nullptr;
    }
}

void AbstractRunner::Init(double iSpeed, char iName[])
{
    // ��ָ�뱣��
    if(iName == nullptr){
        printf("wrong input name.\n");
        return;
    }

    name = new char[strlen(iName)+1];
    strcpy(name, iName);
    // ��ȴʱ��Ĭ��4��
    coolDown = 4.0;
    speed = iSpeed;
    // ������ɫ����Ӧ��ʼ��
    CustInit();

    // ��ʼλ������
    curPosi = STANDARD_DISTANCE * STANDARD_SPEED/speed;
    printf("%s init succed.\n", name);
    inited = true;
}

// ����ӿ���ù̶�����������ģ�巽��ģʽ
// ��0.1��
void AbstractRunner::Run(bool &reached, double &nextPosi)
{
    // ������Ҫʲô����ֵ�����
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

    CustAction();
    // �´�λ�ñ��ΪCDʱ��x��׼����
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
    printf("%s actioned_times(%d) attack_times(%d) with cool_down(%f)\n", name, totalActionTimes, attackTimes, coolDown);
}
