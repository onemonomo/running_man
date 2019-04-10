/*
    遵循原则：当前针对不同角色的不同速度计算方式采用的是模板方法模式，通过定义好接口后
    每个角色自行重写私有的实际方法。
    角色：三藏
*/

#ifndef _SAN_ZANG_
#define _SAN_ZANG_

#include "AbstractRunner.h"

class SanZang : public AbstractRunner
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
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }

    void CustAction(double &iCoolDown)
    {
        int turn = totalActionTimes % 2;
        if (turn == 1)
        {
            iCoolDown = 3 * TALENT_STONE;
            return;
        }
        iCoolDown =3.5 * TALENT_STONE;
        attackTimes++;
    }
};

#endif
