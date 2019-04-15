/*
    面向接口编程，技能抽象接口
*/

#ifndef _ABS_SKILL_
#define _ABS_SKILL_

#include "Common.h"
#include "AbstractCoolDown.h"

class AbstractRunner;

class AbstractSkill : public AbstractCoolDown
{
public:
    AbstractSkill(double iCoolDown) : AbstractCoolDown(iCoolDown)
    {
        owner = nullptr;
        level = 1;
    }
    virtual ~AbstractSkill(){owner = nullptr;}

    virtual void Use(double &oCoolDown) = 0;

    void SetOwner(AbstractRunner *iOwner)
    {
        if(iOwner == nullptr){
            printf("owner null ptr.\n");
            return;
        }
        owner = iOwner;
    }

    virtual void SetLevel(uint iLevel) = 0;

protected:
    AbstractSkill(const AbstractSkill &);
    AbstractSkill& operator=(const AbstractSkill &);
    AbstractRunner *owner;
    uint level;
};

#endif
