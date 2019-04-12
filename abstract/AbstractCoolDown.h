/*
    面向接口编程，由于武器和技能都有CD这一机制，从逻辑上应该将CD机制提出来做成接口。
*/

#ifndef _ABS_CD_
#define _ABS_CD_

#include "Common.h"

class AbstractCoolDown
{
public:
    AbstractCoolDown(double iCoolDown) 
    {
        coolDown = iCoolDown * TALENT_STONE;
    }

    virtual ~AbstractCoolDown(){}

    virtual void RateCD(uint ratio)
    {
        coolDown -= coolDown * ratio / 100;
        printf("RateCD: coolDown(%.3f).\n", coolDown);
    }

protected:
    double coolDown;

};

#endif
