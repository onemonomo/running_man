/*
    面向接口编程，运动员辅助工具类接口
*/

#ifndef _ABSTRACT_WEAPON_
#define _ABSTRACT_WEAPON_

#include "Common.h"
#include "AbstractCoolDown.h"

class AbstractRunner;

class AbstractWeapon : public AbstractCoolDown
{
public:
    AbstractWeapon(double iCoolDown) : AbstractCoolDown(iCoolDown)
    {
        owner = nullptr;
    }
    virtual ~AbstractWeapon(){owner = nullptr;}

public:
    enum QualityLevel
    {
        LOW = 0,
        MID,
        HIGH
    };

    // 原来写在protected里面的,但是友元类是不继承的，得所有角色都申明成友元
    void SetOwner(AbstractRunner *iOwner)
    {
        if(iOwner == nullptr){
            printf("owner null ptr.\n");
            return;
        }
        owner = iOwner;
    }
    // 定义成虚函数主要是给knife自定义
    virtual void Use(double &oCoolDown, uint &oAttackTimes) = 0;

protected:
    AbstractWeapon(const AbstractWeapon &);
    AbstractWeapon& operator=(const AbstractWeapon &);
    
    double cdBonus;
    AbstractRunner *owner;

private:
    uint attackValue;
    QualityLevel quality;

};

#endif // _ABSTRACT_WEAPON_
