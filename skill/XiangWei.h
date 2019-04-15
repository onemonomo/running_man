/*
    第一个技能：相位。
*/

#ifndef _SKILL_XIANGWEI_
#define _SKILL_XIANGWEI_

#include "AbstractSkill.h"
#include "AbstractWeapon.h"

class XiangWei : public AbstractSkill
{
public:
    XiangWei(double iCoolDown) : AbstractSkill(iCoolDown) {}
    ~XiangWei(){};
    
    virtual void Use(double &oCoolDown, AbstractCoolDown* object)
    {
        if(object == nullptr) {
            printf("null ptr.\n");
            oCoolDown = 4;
            return;
        }

        object->RateCD(40);
        oCoolDown = coolDown * 0.6;
    }

    virtual void SetLevel(uint iLevel)
    {
        level = iLevel;
    }
};

#endif
