/*
    ��ѭԭ�򣺵�ǰ��Բ�ͬ��ɫ�Ĳ�ͬ�ٶȼ��㷽ʽ���õ���ģ�巽��ģʽ��ͨ������ýӿں�
    ÿ����ɫ������д˽�е�ʵ�ʷ�����
    ��ɫ����ȸ
*/

#ifndef _YUN_QUE_
#define _YUN_QUE_

#include "AbstractRunner.h"

class YunQue : public AbstractRunner
{
public:
    void YouDang()
    {
        step = 1.2;
    }

    void GuoShang()
    {
        coolDown -= 0.5;
    }

protected:

private:
    void CustInit()
    {
        coolDown = 3;
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }

    void CustAction()
    {
        if (totalActionTimes == 1) {
            XiangWei();
            return;
        }
        attackTimes++;
    }

    void XiangWei()
    {
        coolDown = coolDown*(1-0.35);
    }
};

#endif
