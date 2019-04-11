/*
    遵循原则：当前针对不同角色的不同速度计算方式采用的是模板方法模式，通过定义好接口后
    每个角色自行重写私有的实际方法。
    角色：云雀
*/

#ifndef _YUN_QUE_
#define _YUN_QUE_

#include "AbstractRunner.h"
#include "AbstractWeapon.h"

class YunQue : public AbstractRunner
{
public:
    void YouDang()
    {
        step = 1.2;
    }

protected:

private:
    void CustInit()
    {
        XiangWeiCD = 2.0 * TALENT_STONE;
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }

    void CustAction(double &oCoolDown)
    {
        // 第一次
        if (totalActionTimes == 0) {
            XiangWei();
            oCoolDown = XiangWeiCD; // 相位CD
            return;
        }
        UseWeapon(oCoolDown);
    }

    void XiangWei()
    {
        if (weapon == nullptr){
            printf("no weapon.\n");
            return;
        }
        weapon->RateCD(40);
        XiangWeiCD = XiangWeiCD*(1-0.4);
    }
private:
    double XiangWeiCD;
};

#endif
