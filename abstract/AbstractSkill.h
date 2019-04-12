/*
    面向接口编程，技能抽象接口
*/

#ifndef _ABS_CD_
#define _ABS_CD_

#include "Common.h"
#include "AbstractCoolDown.h"

class AbstractRunner;

class AbstractSkill : AbstractCoolDown
{
public:
    AbstractSkill(double iCoolDown) : AbstractCoolDown(iCoolDown) {}
    virtual ~AbstractSkill(){}

    virtual void Use(double &oCoolDown) = 0;

    void SetOwner(AbstractRunner *iOwner)
    {
        if(iOwner == nullptr){
            printf("owner null ptr.\n");
            return;
        }
        owner = iOwner;
    }

protected:
    double coolDown;
    AbstractRunner *owner;

};

#endif
