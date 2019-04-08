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

protected:

private:
    void CustInit()
    {
        coolDown = 3 * (1.0 - 0.35);
        step = 1.2;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }
};

#endif
