/*
    ��ѭԭ�򣺵�ǰ��Բ�ͬ��ɫ�Ĳ�ͬ�ٶȼ��㷽ʽ���õ���ģ�巽��ģʽ��ͨ������ýӿں�
    ÿ����ɫ������д˽�е�ʵ�ʷ�����
    ��ɫ������
*/

#ifndef _REVENGER_
#define _REVENGER_

#include "AbstractRunner.h"

class Revenger : public AbstractRunner
{
public:

protected:

private:
    void CustInit()
    {
        coolDown = 4;
        step = 1;
        return;
    }

    void CustRun(bool &reached, double &nextPosi)
    {
        return;
    }
};

#endif
