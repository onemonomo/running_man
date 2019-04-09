/*
    �������룬�����쳣�������������ṹ
*/

#ifndef _COMMON_
#define _COMMON_

typedef unsigned int uint;

const double STANDARD_DISTANCE = 10.0;
const double STANDARD_SPEED = 100.0;
const uint TOTAL_STEPS = 100;

#define SUCCESS 0

#define FUNC_ST                     \
    uint __funcReturn = 0x00000001; \
    uint __errorLine = 0xFFFFFFFF;  \
    {

#define FUNC_END                    \
    }                               \
    __JUMP_HERE__:

// ��¼��������
#define JUMP()                      \
    {                               \
        __errorLine = __LINE__;     \
        goto __JUMP_HERE__;         \
    }
// ��������ֱֵ�Ӻ괦��
#define EXEC(func)                  \
    {                               \
        __funcReturn = func;        \
        if ( __funcReturn != SUCCESS ) \
            JUMP()                  \
    }

#define HANDLE_ERROR                \
    {                               \
        printf("error occured at line = %d.\n", __errorLine); \
        // �����󲹾ȴ�ʩ

#define END_HANDLE_ERROR            \
    }

#endif // _COMMON_
