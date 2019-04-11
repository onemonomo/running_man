#ifndef _WEAPON_GUN_
#define _WEAPON_GUN_

#include "AbstractWeapon.h"
#include "Common.h"
#include "AbstractRunner.h"

class Gun : public AbstractWeapon
{
public:
    Gun(uint iBulletNum, double iCoolDown)
    {
        bulletNum = iBulletNum;
        coolDown = iCoolDown;
        bulletUsed = 0;
    }
    virtual ~Gun()
    {
    };

protected:
    virtual void Use(double &oCoolDown)
    {
        if (owner == nullptr) {
            printf("error: no owner.\n");
            return;
        }
        char *owenerName = nullptr;
        owner->GetName(owenerName);
        if (bulletUsed == bulletNum) {
            printf("%s reload the bullet.\n", owenerName);
            oCoolDown = 3 * TALENT_STONE;
            bulletUsed = 0;
            return;
        }

        bulletUsed++;
        oCoolDown = coolDown * TALENT_STONE;
    }

};

#endif // _WEAPON_GUN_
