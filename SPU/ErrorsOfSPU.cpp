#include <stdio.h>
#include <assert.h>

#include "..\TotalFile"
#include "Stack.h"
#include "logfile.h"

void PrintErrorsOfSPU(FILE* fp, int result)
    {
    assert(fp);

    if ((result & (int)ErrorsOfSPU::ERROR_SIGNATURE)       != 0)
        fprintf(fp, "You have problems with signature, are you sure about your file?\n");

    if ((result & (int)ErrorsOfSPU::ERROR_VERSION)         != 0)
        fprintf(fp, "You have problems with version, are you sure about your file?\n");

    if ((result & (int)ErrorsOfSPU::ERROR_MEMMORY)         != 0)
        fprintf(fp, "Address of data != nullptr\n");

    if ((result & (int)ErrorsOfSPU::ERROR_UNKNOWN_COMMAND) != 0)
        fprintf(fp, "An unknown command has been encountered, please check your file\n");

    if ((result & (int)ErrorsOfSPU::ERROR_FILE)            != 0)
        fprintf(fp, "You have problems working with the file\n");
    }

//-----------------------------------------------------------------------------

int ProcessorOk(FILE* fp, struct Processor* spu)
    {
    int result = 0;
    VERIFY(&(spu->stk));
    if (spu == nullptr)
        {
        result |= (int)ErrorsOfSPU::ERROR_MEMMORY);
        }

    if (spu->native == NULL)
        {
        result |= (int)ErrorsOfSPU::ERROR_FILE);
        }

    PrintErrorsOfSPU(fp, result);
    return result;
    }

//-----------------------------------------------------------------------------
