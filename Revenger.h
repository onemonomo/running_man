/*
    遵循原则：当前针对不同角色的不同速度计算方式采用的是模板方法模式，通过定义好接口后
    每个角色自行重写私有的实际方法。
    角色：主角
*/

#ifndef _REVENGER_
#define _REVENGER_

#include "AbstractRunner.h"
#include "Gun.h"

class Revenger : public AbstractRunner
{
public:

protected:

private:
    void CustInit()
    {
        step = 1;
        return;
    }
    /*
    void CustAction(double &iCoolDown)
    {
        int turn = totalActionTimes % 3;
        if (turn == 2)
        {
            iCoolDown = 3 * TALENT_STONE;
            return;
        }
        iCoolDown = 4 * TALENT_STONE;
        attackTimes++;
    }
    */
    void CustAction(double &iCoolDown)
    {
        if(weapon == nullptr){
            printf("no weapon.\n");
            return;
        }
        weapon->Use(iCoolDown);
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }
};

#endif
