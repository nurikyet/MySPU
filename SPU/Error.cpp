#include <stdio.h>
#include <assert.h>

#include "..\Types.h"
#include "Hash.h"
#include "Stack.h"
#include "logfile.h"
#include "Error.h"

#define ABOBA()(printf("\n<<I work in a FILE %s(%d) in %s>>\n", __FILE__, __LINE__, __func__))

void PrintError(FILE* fp, int result)
    {
    ABOBA();
    assert(fp);
    ABOBA();
    IF_HASH
    (
        if ((result & (int)Error::ERROR_DATA) != 0)
            fprintf(fp, "You have error in data, when you work with hash, please check your all addresses \n");
        if ((result & (int)Error::ERROR_STRUCT) != 0)
            fprintf(fp, "You have error in struct, when you work with hash, please check your all addresses \n");
    )

    IF_CANARY
    (
        if ((result & (int)Error::ERROR_DATA_CANARY) != 0)
            fprintf(fp, "You have error in canary of data, please check your all addresses \n");
    )

    if ((result & (int)Error::ERROR_CAPACITY) != 0)
        fprintf(fp, "Capacity must be > 0\n");

    if ((result & (int)Error::ERROR_SIZE) != 0)
        fprintf(fp, "Size must be <= capacity\n");

    if ((result & (int)Error::ERROR_DATA) != 0)
        fprintf(fp, "address of data != nullptr\n");

    if ((result & (int)Error::ERROR_STRUCT) != 0)
        fprintf(fp, "address of struct != nullptr\n");

    ABOBA();

    }

//-----------------------------------------------------------------------------

int StackOk(FILE* fp, struct stack* stk)
    {
    ABOBA();
    int result = 0;
    IF_HASH
    (
        if (HashOkData(stk) == 0)
            {
            result |= (int)Error::ERROR_DATA;
            }
        if (HashOkStruct(stk) == 0)
            {
            result |= (int)Error::ERROR_STRUCT;
            }
    )
    ABOBA();
    IF_CANARY
    (
        if (stk->stack_first != canary_value or stk->stack_last != canary_value)
            {
            result |= (int)Error::ERROR_STRUCT_CANARY;
            }

        canary_t* first_canary  = (canary_t*)((char*) stk->data - sizeof(canary_t));
        canary_t* last_canary   = (canary_t*)((char*) stk->data + (stk->capacity) * sizeof(elem_t));

        if (*first_canary != canary_value)
            {
            result |= (int)Error::ERROR_DATA_CANARY;
            }
        if (*last_canary != canary_value)
            {
            result |= (int)Error::ERROR_DATA_CANARY;
            }
    )
    ABOBA();
    if (!stk->capacity)
        {
        result |= (int)Error::ERROR_CAPACITY;
        }
    ABOBA();
    if (stk->capacity < 0)
        {
        result |= (int)Error::ERROR_CAPACITY;
        }
    if (stk->size > stk->capacity)
        {
        result |= (int)Error::ERROR_SIZE;
        }
    ABOBA();
    if (!stk->data)
        {
        result |= (int)Error::ERROR_DATA;
        }
    ABOBA();
    if (stk == nullptr)
        {
        result |= (int)Error::ERROR_STRUCT;
        }
    ABOBA();
    //PrintError(fp, result);
    ABOBA();
    printf("MY RESULT IS %d\n", result);
    return result;
    }
