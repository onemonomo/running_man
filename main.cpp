#include "Common.h"
#include "PlayGroundOne.h"
#include "YunQue.h"
#include "Revenger.h"
#include "SanZang.h"
#include "HaiXiu.h"
#include "Gun.h"
#include "Blade.h"

using namespace std;

uint TOTAL_STEPS = 100;

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

uint TRACK_NUM  = 5;

int match2()
{
    TOTAL_STEPS = 150;
    TRACK_NUM = 5;
    SanZang *runner1 = new SanZang;
    runner1->Init(115, "115 SanZang");
    runner1->YouDang();
    Gun *ZhongHuoQi = new Gun(1, 3.5);
    runner1->AddWeapon(ZhongHuoQi);

    Revenger *runner2 = new Revenger;
    runner2->Init(100, "100 Rvenger");
    Gun *XianDan = new Gun(2, 4);
    runner2->AddWeapon(XianDan);

    YunQue *runner3 = new YunQue;
    runner3->Init(130, "130 YunQue ");
    runner3->YouDang();
    Blade *Putong = new Blade(3);
    runner3->AddWeapon(Putong);

    HaiXiu *runner4 = new HaiXiu;
    runner4->Init(114, "114 HaiXiu ");
    Gun *JuJiQiang = new Gun(2, 4.5);
    runner4->AddWeapon(JuJiQiang);

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
    delete runner4;
/*
    标准结果：
    115 SanZang actioned_times(7) attack_times(4)
    100 Rvenger actioned_times(4) attack_times(3)
    130 YunQue  actioned_times(14) attack_times(13)
    114 HaiXiu  actioned_times(5) attack_times(4)
*/
    return 0;
}


int main()
{
    match2();
    return 0;
}
