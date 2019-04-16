/*
    公共代码，包括异常处理和重命名结构
*/

#ifndef _COMMON_
#define _COMMON_

#include <iostream>
typedef unsigned int uint;

const double STANDARD_DISTANCE = 10.0;
const double STANDARD_SPEED = 100.0;
const double TALENT_STONE = 0.95; // 刻印减5%cd
extern uint TOTAL_STEPS;

#define SUCCESS 0

/*

void func()
{
    uint error_line_number = 0;
    uint error_code = 0;
    // 函数体
    {
        int ret = call();
        if (ret != SUCCESS) { error_line_num = __LINE__; error_code = ret; goto record_log;}

        return;
    }
    record_log:
    {
        do sth;
    }
}
*/

#define FUNC_ST                     \
    uint __funcReturn = 0x00000001; \
    uint __errorLine = 0xFFFFFFFF;  \
    {

#define FUNC_END                    \
    }                               \
    __JUMP_HERE__:

// 记录错误行数
#define JUMP()                      \
    {                               \
        __errorLine = __LINE__;     \
        goto __JUMP_HERE__;         \
    }
// 函数返回值直接宏处理
#define EXEC(func)                  \
    {                               \
        __funcReturn = func;        \
        if ( __funcReturn != SUCCESS ) \
            JUMP()                  \
    }

#define HANDLE_ERROR                \
    {                               \
        printf("error occured at line = %d.\n", __errorLine); \
        // 做错误补救措施

#define END_HANDLE_ERROR            \
    }

class AutoFree
{
public:
    AutoFree(void *ptr)
    {
        autoFree = ptr;
    }

    ~AutoFree()
    {
        if (autoFree != nullptr)
            delete autoFree;
    }
    void *autoFree;

    // 如果要支持复制构造和赋值运算，那么就要转移控制权
    AutoFree(AutoFree &tmp)
    {
        autoFree = tmp.autoFree;
        tmp.autoFree = nullptr;
    }

    AutoFree& operator=(AutoFree &tmp)
    {
        autoFree = tmp.autoFree;
        tmp.autoFree = nullptr;
    }
};

#endif // _COMMON_
