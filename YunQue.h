/*
    遵循原则：当前针对不同角色的不同速度计算方式采用的是模板方法模式，通过定义好接口后
    每个角色自行重写私有的实际方法。
    角色：云雀
*/

#ifndef _YUN_QUE_
#define _YUN_QUE_

#include "AbstractRunner.h"

class YunQue : public AbstractRunner
{
public:
    virtual ~YunQue(){printf("~YunQue.\n");}
    void YouDang()
    {
        step = 1.2;
    }

    void GuoShang()
    {
        coolDown -= 0.5;
    }

protected:

private:
    void CustInit()
    {
        coolDown = 3;
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }

    void CustAction()
    {
        if (totalActionTimes == 1) {
            XiangWei();
            return;
        }
        attackTimes++;
    }

    void XiangWei()
    {
        coolDown = coolDown*(1-0.35);
    }
};

#endif
