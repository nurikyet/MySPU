#include <stdio.h>
#include <math.h>

#include "Commands.h"
#include "SPU.h"
#include "..\Types.h"
#include "..\TotalFile.h"
#include "..\Stack.h"

//-----------------------------------------------------------------------------

int ProcessorCos(struct Processor* spu)
    {
    elem_t element  = POISON;
    StackPop(&(spu->stk), &element);

    elem_t result = COEFFICIENT * cos((double)element / COEFFICIENT);

    StackPush(&(spu->stk), result);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorSin(struct Processor* spu)
    {
    elem_t element  = POISON;

    StackPop(&(spu->stk), &element);

    elem_t result = COEFFICIENT * sin((double)element / COEFFICIENT);

    StackPush(&(spu->stk), result);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorAdd(struct Processor* spu)
    {
    elem_t first_element  = POISON;
    elem_t second_element = POISON;

    StackPop(&(spu->stk), &first_element);
    StackPop(&(spu->stk), &second_element);

    elem_t sum = first_element + second_element;

    StackPush(&(spu->stk), sum);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorSub(struct Processor* spu)
    {
    elem_t first_element  = POISON;
    elem_t second_element = POISON;

    StackPop(&(spu->stk), &first_element);
    StackPop(&(spu->stk), &second_element);

    elem_t sub = first_element - second_element;

    StackPush(&(spu->stk), sub);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorOut(struct Processor* spu)
    {
    elem_t ret_value = POISON;

    StackPop(&(spu->stk), &ret_value);

    PROCESSOR_VERIFY(spu);
    printf("Result is %lg\n", (double) ret_value / COEFFICIENT);
    }

//-----------------------------------------------------------------------------

int ProcessorIn(struct Processor* spu)
    {
    elem_t element = POISON;
    scanf("%d", &element);
    StackPush(&spu->stk, element);
    }

//-----------------------------------------------------------------------------

int ProcessorDiv(struct Processor* spu)
    {
    elem_t first_element  = POISON;
    elem_t second_element = POISON;

    StackPop(&(spu->stk), &first_element);
    StackPop(&(spu->stk), &second_element);

    elem_t div = COEFFICIENT * first_element / second_element;

    StackPush(&(spu->stk), div);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorMul(struct Processor* spu)
    {
    elem_t first_element  = POISON;
    elem_t second_element = POISON;

    StackPop(&(spu->stk), &first_element);
    StackPop(&(spu->stk), &second_element);

    elem_t mul = first_element * second_element / COEFFICIENT;

    StackPush(&(spu->stk), mul);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorSqrt(struct Processor* spu)
    {
    elem_t element  = POISON;

    StackPop(&(spu->stk), &element);

    elem_t result = sqrt(element);

    StackPush(&(spu->stk), result);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorTg(struct Processor* spu)
    {
    elem_t element  = POISON;
    StackPop(&(spu->stk), &element);

    elem_t result = COEFFICIENT * tan((double)element / COEFFICIENT);

    StackPush(&(spu->stk), result);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorCtg(struct Processor* spu)
    {
    elem_t element  = POISON;
    StackPop(&(spu->stk), &element);

    elem_t ctg = COEFFICIENT * (1 / tan((double)element / COEFFICIENT));

    StackPush(&(spu->stk), ctg);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

void ProcessorCat()
    {
    printf(
                "   /\\_/\\    \n"
                "   >^,^<      \n"
                "    / \\      \n"
                "    (__)__    \n");
    }

//-----------------------------------------------------------------------------

int ProcessorPow(struct Processor* spu)
    {
    elem_t first_element  = POISON;
    elem_t second_element = POISON;

    StackPop(&(spu->stk), &first_element);
    StackPop(&(spu->stk), &second_element);

    elem_t power = pow(first_element, second_element);

    StackPush(&(spu->stk), power);

    PROCESSOR_VERIFY(spu);
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

void ProcessorDog()
    {
    printf(
    "____________________¶¶¶¶¶¶¶¶¶¶¶        \n"
    "__________________¶¶¶¶_____¶¶¶¶¶¶¶     \n"
    "_________________¶¶_____________¶¶¶    \n"
    "_______________¶¶¶______________¶_¶¶   \n"
    "______________¶¶______________¶¶¶¶__¶  \n"
    "_____________¶¶__¶____________¶0¶¶¶_¶  \n"
    "_____________¶¶¶_¶¶____¶¶_____¶¶¶¶¶¶¶  \n"
    "____________¶¶_¶__¶¶__¶¶0¶_______¶¶¶¶  \n"
    "____________¶_____¶¶¶_¶¶¶¶_______¶¶_¶¶ \n"
    "____________¶______¶¶¶_________¶_¶¶_¶¶ \n"
    "____________¶¶______¶¶¶_____¶¶¶_¶_¶¶¶  \n"
    "____________¶¶¶_____¶¶_¶____¶¶¶¶¶_¶    \n"
    "__________¶¶¶_¶¶_____¶_¶¶¶___¶¶¶¶¶¶    \n"
    "_¶¶¶_____¶¶____¶¶¶___¶¶__¶¶¶¶¶¶¶¶¶     \n"
    "¶¶¶¶____¶¶_______¶¶¶¶¶__________¶¶     \n"
    "¶¶¶¶____¶_________¶¶¶___________¶¶     \n"
    "¶¶_¶___¶¶_______________________¶      \n"
    "_¶¶¶¶__¶_______________________¶¶      \n"
    "__¶¶¶¶¶¶____¶¶______¶__________¶¶      \n"
    "___¶¶_¶¶____¶¶_____¶¶_______¶¶_¶¶      \n"
    "_____¶¶¶____¶¶_____¶________¶__¶¶      \n"
    "______¶¶¶____¶____¶¶_¶¶¶¶¶¶____¶¶      \n"
    "_______¶¶¶___¶_____¶____¶¶¶____¶¶¶¶    \n"
    "________¶¶¶¶_¶_____¶¶__¶¶_¶¶___¶¶¶¶    \n"
    "______¶¶_¶_¶¶¶_____¶¶¶¶¶__¶___¶¶       \n"
    "______¶¶¶¶¶¶¶¶¶____¶¶¶____¶___¶¶¶¶     \n"
    "______________¶¶_¶¶¶¶¶¶___¶¶¶¶¶¶¶¶     \n"
    "_______________¶¶¶¶¶¶______¶¶¶¶¶       \n"
    );
    }

//-----------------------------------------------------------------------------

