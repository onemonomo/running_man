#include <iostream>
#include "YunQue.h"
#include "Common.h"

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

int main()
{
    test_func();
    AbstractRunner *runner1 = new YunQue;

    runner1->Init(130, "YunQue");
    runner1->Run();
    runner1->PrintName();
    return 0;
}
