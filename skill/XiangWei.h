/*
    第一个技能：相位。
*/

#ifndef _SKILL_XIANGWEI_
#define _SKILL_XIANGWEI_

#include "AbstractSkill.h"
#include "AbstractRunner.h"

class XiangWei : public AbstractSkill
{
public:
    XiangWei(double iCoolDown):AbstractSkill(iCoolDown) {}
    ~XiangWei(){};
    virtual void Use(double &oCoolDown)
    {
        if(owner == nullptr) {
            printf("use skill with no owner.\n");
            oCoolDown = 4;
            return;
        }

        owner->

    }
}

#endif