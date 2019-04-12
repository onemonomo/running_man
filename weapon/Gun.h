#ifndef _WEAPON_GUN_
#define _WEAPON_GUN_

#include "AbstractWeapon.h"
#include "Common.h"
#include "AbstractRunner.h"

class Gun : public AbstractWeapon
{
public:
    Gun(uint iBulletNum, double iCoolDown, double iCdBonus = 0) : AbstractWeapon(iCoolDown)
    {
        bulletNum = iBulletNum;
        cdBonus = iCdBonus; // 应该不受刻印影响
        reloadCD = 3 * TALENT_STONE;
        bulletUsed = 0;
    }
    virtual ~Gun() {};

    virtual void Use(double &oCoolDown, uint &oAttackTimes)
    {
        if (owner == nullptr) {
            printf("error: no owner.\n");
            return;
        }
        char *ownerName = nullptr;
        owner->GetName(ownerName);
        if (bulletUsed == bulletNum) {
            printf("%s reload the bullet.\n", ownerName);
            oCoolDown = reloadCD;
            bulletUsed = 0;
            return;
        }
        printf("%s biu! open fire!!!\n", ownerName);
        bulletUsed++;
        oAttackTimes++;
        oCoolDown = coolDown - cdBonus;
    }
private:
    uint bulletNum;
    uint bulletUsed;
    double reloadCD;
};

#endif // _WEAPON_GUN_
