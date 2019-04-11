#ifndef _WEAPON_BLADE_
#define _WEAPON_BLADE_

#include "AbstractWeapon.h"

class Blade : public AbstractWeapon
{
public:
    Blade(double iCoolDown, double iCdBonus = 0)
    {
        coolDown = iCoolDown * TALENT_STONE;
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
    // 暂时先给刀一个减CD比例的接口，后续应该新定义一个抽象类CoolDown，因为技能也有CD，应该跟武器统一起来---todo
    virtual void RateCD(uint ratio)
    {
        coolDown -= coolDown * ratio / 100;
        printf("RateCD: coolDown(%.3f).\n", coolDown);
    }
};

#endif // _WEAPON_BLADE_
