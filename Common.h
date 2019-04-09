/*
    公共代码，包括异常处理和重命名结构
*/

#ifndef _COMMON_
#define _COMMON_

typedef unsigned int uint;

const double STANDARD_DISTANCE = 10.0;
const double STANDARD_SPEED = 100.0;
const double TALENT_STONE = 0.95; // 刻印减5%cd
const uint TOTAL_STEPS = 200;

#define SUCCESS 0

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

#endif // _COMMON_