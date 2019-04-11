/*
    面向接口编程，运动员辅助工具类接口
*/

#ifndef _ABSTRACT_WEAPON_
#define _ABSTRACT_WEAPON_

#include "Common.h"

class AbstractRunner;

class AbstractWeapon
{
public:
    AbstractWeapon();
    virtual ~AbstractWeapon();
public:
    enum QualityLevel
    {
        LOW = 0,
        MID,
        HIGH
    };
protected:
    // 定义成虚函数主要是给knife自定义
    virtual void Use(double &oCoolDown);

private:
    uint attackValue;
    uint bulletNum;
    uint bulletUsed;
    double coolDown;
    QualityLevel quality;
    AbstractRunner *owner;
};

#endif // _ABSTRACT_WEAPON_
