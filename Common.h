/*
    公共代码，包括异常处理和重命名结构
*/

#ifndef _COMMON_
#define _COMMON_

typedef unsigned int uint;

#define SUCCESS 0

#define FUNC_ST                     \
    uint __funcReturn = 0x00000001; \
    uint __errorLine = 0xFFFFFFFF;  \
    {

#define FUNC_END                    \
    }                               \
    __JUMP_HERE__:

// 记录错误行数
#define THROW()            \
    {                               \
        __errorLine = __LINE__; \
        goto __JUMP_HERE__;         \
    }
// 函数返回值直接宏处理
#define EXEC(func)                  \
    {                               \
        __funcReturn = func;        \
        if ( __funcReturn != SUCCESS ) \
            THROW()                 \
    }

#define HANDLE_ERROR                \
    {                               \
        printf("error occured at line = %d.\n", __errorLine); \
        // 做错误补救措施

#define END_HANDLE_ERROR            \
    }

#endif // _COMMON_