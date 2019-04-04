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
    };

    AbstractPlayGround(){inited = false; trackList = nullptr;}
    virtual ~AbstractPlayGround();

    void Init(int iTrackNum)
    {
        trackNumber = iTrackNum;

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

        int time = 0;
        while(time < 100){
            time++;
            for(int i=0; i < playerNumber; i++){
                trackList[i].player->Run();
            }
        }
    }

    void AddRunner(AbstractRunner *iRunner)
    {
        return;
    }
private:
    void CustInit() = 0;
    int trackNumber;
    int trackLength;
    int playerNumber;
    Track *trackList;
    bool inited;

};
#endif // _ABSTRACT_PLAYGROUND_
