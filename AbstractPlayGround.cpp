#include "AbstractPlayGround.h"



AbstractPlayGround::AbstractPlayGround()
{
    cleanMode = true;
    inited = false;
    trackList = nullptr;
};

AbstractPlayGround::~AbstractPlayGround()
{
    if (trackList != nullptr){
        delete [] trackList;
        trackList = nullptr;
    }
};

void AbstractPlayGround::Init(uint iTrackNum, bool iCleanMode)
{
    cleanMode = iCleanMode;
    trackNumber = iTrackNum;

    // 设置运动员数为0
    playerNumber = 0;
    trackList = new Track[iTrackNum];
    CustInit();
    inited = true;
}

void AbstractPlayGround::StartRun()
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
        printf("player number abnormal = %d.\n", playerNumber);
        return;
    }

    uint time = 0;
    while(time < TOTAL_STEPS){
        time++;
        for(uint i=0; i < playerNumber; i++){
            double tmp = 1;
            trackList[i].player->Run(trackList[i].reached, tmp);
        }

        if (cleanMode == false){
            for(uint i = 0; i < playerNumber; i++){
                trackList[i].player->PrintName();
            }
        }

        for(uint i = 0; i < playerNumber; i++){
            if (trackList[i].reached == 1){
                trackList[i].player->Action();
            }
        }
    }
    for(uint i = 0; i < playerNumber; i++){
        trackList[i].player->Report();
    }
}

void AbstractPlayGround::AddRunner(AbstractRunner *iRunner)
{
    if (iRunner == nullptr) {
        printf("input is null ptr.\n");
        return;
    }
    if (trackList == nullptr) {
        printf("track is null ptr.\n");
        return;
    }
    if (playerNumber >= trackNumber) {
        printf("too many player.\n");
        return;
    }

    trackList[playerNumber++].player = iRunner;
    printf("add player success.\n");
    return;
}
