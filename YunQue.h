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
    void YouDang()
    {
        step = 1.2;
    }

    void GuoShang()
    {
        weaponCD -= 0.5;
    }

    void GuoShang2()
    {
        weaponCDPlus = -0.5;
    }

    void ZaiBuZhan()
    {
        weaponCD -= 0.2;
    }

    void ZaiBuZhan2()
    {
        weaponCDPlus = -0.2;
    }
protected:

private:
    void CustInit()
    {
        weaponCD = 3.0 * TALENT_STONE;
        XiangWeiCD = 2.0 * TALENT_STONE;
        weaponCDPlus = 0;
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }

    void CustAction(double &iCoolDown)
    {
        // 第一次
        if (totalActionTimes == 0) {
            XiangWei();
            iCoolDown = XiangWeiCD; // 相位CD
            return;
        }
        iCoolDown = weaponCD + weaponCDPlus;
        attackTimes++;

    }

    void XiangWei()
    {
        weaponCD = weaponCD*(1-0.4);
        XiangWeiCD = XiangWeiCD*(1-0.4);
    }
private:
    double weaponCD;
    double weaponCDPlus;
    double XiangWeiCD;
};

#endif
