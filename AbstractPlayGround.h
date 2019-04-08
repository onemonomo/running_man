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
        uint currentPosi; // 当前运动员的相对起点位置
    };

    AbstractPlayGround(){inited = false; trackList = nullptr;}
    virtual ~AbstractPlayGround();

    void Init(uint iTrackNum)
    {
        trackNumber = iTrackNum;

        // 设置运动员数为0
        playerNumber = 0;
        trackList = new Track[iTrackNum];
        CustInit();
        inited = true;
    }

    void StartRun()
    {
        // 判断是否已经初始化
        if (inited == false) {
            printf("play ground not ready.\n");
            return;
        }

        if (trackList == nullptr){
            printf("play not ready.\n");
            return;
        }

        if (playerNumber == 0 || playerNumber > trackNumber){
            printf("player number abnormal = %d.\n", pljayerjNumber);
            return;
        }

        uint time = 0;
        while(time < 100){
            time++;
            for(uint i=0; i < playerNumber; i++){
                trackList[i].player->Run();
            }
        }
    }

    void AddRunner(AbstractRunner *iRunner)
    {
        if (iRunner == nullptr) {
            printf("input is null ptr.\n");
            return;
        }
        if (trackList == nullptr) {
            printf("track is null ptr.\n");
            return;
        }
        if (playerNumber > trackNumber) {
            printf("too many player.\n");
            return;
        }
        
        trackList[playerNumber++].player = iRunner;
        trackList[playerNumber].currentPosi = 0; // 初始位置都为0
        printf("add player success.\n");
        return;
    }
private:
    void CustInit() = 0;
    uint trackNumber;
    uint trackLength;
    uint playerNumber;
    Track *trackList;
    bool inited;

};
#endif // _ABSTRACT_PLAYGROUND_
