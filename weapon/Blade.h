#ifndef _WEAPON_BLADE_
#define _WEAPON_BLADE_

#include "AbstractWeapon.h"

class Blade : public AbstractWeapon
{
public:
    Blade(double iCoolDown, double iCdBonus = 0) : AbstractWeapon(iCoolDown)
    {
        cdBonus = iCdBonus; // 应该不受刻印影响
    }
    virtual ~Blade()
    {
    };
// 基类明明已经把Use申明在public且删除了友元申明，但是子类申明成的protected居然还能在abstractRunner中访问---todo
    virtual void Use(double &oCoolDown, uint &oAttackTimes)
    {
        if (owner == nullptr) {
            printf("error: no owner.\n");
            return;
        }
        char *ownerName = nullptr;
        owner->GetName(ownerName);

        printf("%s shua! blade out!!!\n", ownerName);
        oAttackTimes++;
        oCoolDown = coolDown - cdBonus;
    }

};

#endif // _WEAPON_BLADE_
