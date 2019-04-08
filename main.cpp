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

#define TRACK_NUM 2

int main()
{
    AbstractRunner *runner1 = new YunQue;
    runner1->Init(130, "YunQue");
    AbstractRunner *runner2 = new Revenger;
    runner2->Init(100, "Rvenger");
    PlayGroundOne *playGround1 = new PlayGroundOne;
    playGround1->Init(TRACK_NUM);
    playGround1->AddRunner(runner1);
    playGround1->AddRunner(runner2);
    playGround1->StartRun();
    return 0;
}
