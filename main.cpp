#include "Common.h"
#include "PlayGroundOne.h"
#include "YunQue.h"
#include "Revenger.h"
#include "SanZang.h"
#include "HaiXiu.h"

using namespace std;

int test_func()
{
FUNC_ST
    EXEC(4);
    return 4;
FUNC_END
HANDLE_ERROR
    return 5;
END_HANDLE_ERROR
}

#define TRACK_NUM 8

int match1()
{
    AbstractRunner *runner1 = new YunQue;
    runner1->Init(130, "130 YunQue    ");
    AbstractRunner *runner2 = new Revenger;
    runner2->Init(110, "110 Rvenger   ");
    YunQue *runner3 = new YunQue;
    runner3->Init(130, "130 YunQue(YD)");
    runner3->YouDang();
    YunQue *runner4 = new YunQue;
    runner4->Init(130, "130 YunQue(GS)");
    runner4->GuoShang();
    YunQue *runner5 = new YunQue;
    runner5->Init(130, "130 YunQue(YD+GS)");
    runner5->YouDang();
    runner5->GuoShang();

    PlayGroundOne *playGround1 = new PlayGroundOne;
    playGround1->Init(TRACK_NUM);
    playGround1->AddRunner(runner1);
    playGround1->AddRunner(runner2);
    playGround1->AddRunner(runner3);
    playGround1->AddRunner(runner4);
    playGround1->AddRunner(runner5);
    playGround1->StartRun();
    delete runner1;
    delete runner2;
    delete runner3;
    return 0;
}


int match2()
{
    SanZang *runner1 = new SanZang;
    runner1->Init(115, "115 SanZang");
    runner1->YouDang();
    Revenger *runner2 = new Revenger;
    runner2->Init(100, "100 Rvenger");
    YunQue *runner3 = new YunQue;
    runner3->Init(130, "130 YunQue ");
    runner3->YouDang();
    HaiXiu *runner4 = new HaiXiu;
    runner4->Init(114, "114 HaiXiu ");

    PlayGroundOne *playGround1 = new PlayGroundOne;
    playGround1->Init(TRACK_NUM);
    playGround1->AddRunner(runner1);
    playGround1->AddRunner(runner2);
    playGround1->AddRunner(runner3);
    playGround1->AddRunner(runner4);
    playGround1->StartRun();
    delete runner1;
    delete runner2;
    delete runner3;
    return 0;
}

int match3()
{
    YunQue *runner1 = new YunQue;
    runner1->Init(130, "YunQue        ");
    YunQue *runner3 = new YunQue;
    runner3->Init(130, "YunQue(YD)    ");
    runner3->YouDang();
    YunQue *runner4 = new YunQue;
    runner4->Init(130, "YunQue(GS)    ");
    runner4->GuoShang();
    YunQue *runner2 = new YunQue;
    runner2->Init(130, "YunQue(YD+ZBZ)");
    runner2->YouDang();
    runner2->ZaiBuZhan();
    YunQue *runner5 = new YunQue;
    runner5->Init(130, "YunQue(YD+GS) ");
    runner5->YouDang();
    runner5->GuoShang();
    YunQue *runner6 = new YunQue;
    runner6->Init(130, "YunQue(GS2)   ");
    runner6->GuoShang2();
    YunQue *runner7 = new YunQue;
    runner7->Init(130, "YunQue(YD+ZBZ2)");
    runner7->YouDang();
    runner7->ZaiBuZhan2();
    YunQue *runner8 = new YunQue;
    runner8->Init(130, "YunQue(YD+GS2) ");
    runner8->YouDang();
    runner8->GuoShang2();

    PlayGroundOne *playGround1 = new PlayGroundOne;
    playGround1->Init(TRACK_NUM);
    playGround1->AddRunner(runner1);
    playGround1->AddRunner(runner3);
    playGround1->AddRunner(runner4);
    playGround1->AddRunner(runner2);
    playGround1->AddRunner(runner5);
    playGround1->AddRunner(runner6);
    playGround1->AddRunner(runner7);
    playGround1->AddRunner(runner8);
    playGround1->StartRun();
    delete runner1;
    delete runner2;
    delete runner3;
    return 0;
}

int main()
{
    match3();
    return 0;
}
