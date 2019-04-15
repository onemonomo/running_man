/*
    遵循原则：当前针对不同角色的不同速度计算方式采用的是模板方法模式，通过定义好接口后
    每个角色自行重写私有的实际方法。
    角色：云雀
*/

#ifndef _YUN_QUE_
#define _YUN_QUE_

#include "AbstractRunner.h"
#include "AbstractWeapon.h"
#include "XiangWei.h"

class YunQue : public AbstractRunner
{
public:
    YunQue()
    {
        skill = new XiangWei(2.0 * TALENT_STONE);
        skill->SetOwner(this);
    }
    void YouDang()
    {
        step = 1.2;
    }

private:
    void CustInit()
    {
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }

    void CustSkillOne(double &oCoolDown)
    {
        // 由于技能类没有了统一的use接口，这里需要强转实际技能类
        // 对于扩展性来说，个人感觉这样更方便扩展。如果使用了统一的use(oCoolDown)接口函数，那么后续的入参
        // 就只能放到XiangWei中作局部变量，违反迪米特原则。
        ((XiangWei*)skill)->Use(oCoolDown, weapon);
        // 后续需要降低其他技能的CD，直接扩展
    }

    void CustAction(double &oCoolDown)
    {
        // 第一次
        if (totalActionTimes == 0) {
            CustSkillOne(oCoolDown);
            return;
        }
        UseWeapon(oCoolDown);
    }

};

#endif