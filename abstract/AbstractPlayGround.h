/*
    遵循原则：依赖倒转原则，面向接口编程
    抽象playground类
*/

#ifndef _ABSTRACT_PLAYGROUND_
#define _ABSTRACT_PLAYGROUND_

#include "AbstractRunner.h"

class AbstractPlayGround
{
public:

    struct Track
    {
        AbstractRunner *player;
        bool reached; // 是否到达终点
    };

    AbstractPlayGround();
    virtual ~AbstractPlayGround();
    void Init(uint iTrackNum, bool iCleanMode = true);
    void StartRun();
    void AddRunner(AbstractRunner *iRunner);

private:
    virtual void CustInit() = 0;
    // 禁用复制构造和赋值运算
    AbstractPlayGround(const AbstractPlayGround&);
    AbstractPlayGround& operator=(const AbstractPlayGround&);

private:
    uint trackNumber;
    double trackLength;
    Track *trackList;
    uint playerNumber;
    bool inited;
    bool cleanMode;
};
#endif // _ABSTRACT_PLAYGROUND_
