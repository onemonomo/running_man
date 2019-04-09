#include "Common.h"
#include "PlayGroundOne.h"
#include "YunQue.h"
#include "Revenger.h"

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

#define TRACK_NUM 5

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

int main()
{
    match1();
    return 0;
}
