/*
    遵循原则：当前针对不同角色的不同速度计算方式采用的是模板方法模式，通过定义好接口后
    每个角色自行重写私有的实际方法。
    角色：害羞
*/

#ifndef _HAI_XIU_
#define _HAI_XIU_

#include "AbstractRunner.h"

class HaiXiu : public AbstractRunner
{
public:

protected:

private:
    void CustInit()
    {
        coolDown = 4.5;
        step = 1;
        return;
    }

    void CustAction()
    {
        attackTimes++;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }
};

#endif
