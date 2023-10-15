#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include "SPU.h"
#include "Commands.h"
#include "SpeakCommands.h"
#include "..\TotalFile.h"
#include "..\Types.h"
#include "..\Stack.h"

int Compare(struct Processor* spu)
    {
    int ccode = 0;
              // but 1 int in file is commands + their arguments quantity!
    while (true)
        {
        ccode    = spu->codeArray[spu->position++];

        switch (ccode)
            {
            case ((int)Commands::CPUSH):
                ProcessorPush(spu);
                break;
            case ((int)Commands::CIN):
                ProcessorIn(spu);
                break;
            case ((int)Commands::COUT):
                ProcessorOut(spu);
                break;
            case ((int)Commands::CSUB):
                ProcessorSub(spu);
                break;
            case ((int)Commands::CADD):
                ProcessorAdd(spu);
                break;
            case ((int)Commands::CMUL):
                ProcessorMul(spu);
                break;
            case ((int)Commands::CDIV):
                ProcessorDiv(spu);
                break;
            case ((int)Commands::CSQRT):
                ProcessorSqrt(spu);
                break;
            case ((int)Commands::CSIN):
                ProcessorSin(spu);
                break;
            case ((int)Commands::CCOS):
                ProcessorCos(spu);
                break;
            case ((int)Commands::CPUSH_R):
                ProcessorPushR(spu);
                break;
            case ((int)Commands::CTG):
                ProcessorTg(spu);
                break;
            case ((int)Commands::CCTG):
                ProcessorCtg(spu);
                break;
            case ((int)Commands::CPOW):
                ProcessorPow(spu);
                break;
            case ((int)Commands::CCAT):
                ProcessorCat();
                break;
            case ((int)Commands::CDOG):
                ProcessorDog();
                break;
            case ((int)Commands::CSLEEP):
                ProcessorSleep();
                break;
            case ((int)Commands::CDEADLINE):
                ProcessorDeadline();
                break;
            case ((int)Commands::CBOTAY):
                ProcessorBotay();
                break;
            case ((int)Commands::CHLT):
                return (int)Error::NO_ERROR;
            default:
                fprintf(stderr, "%d - unknown command code, are you confident in your actions?\n", ccode);
                break;
            }
        PROCESSOR_VERIFY(spu)
        }
    }

//-----------------------------------------------------------------------------

int ProcessorCtor(struct Processor* spu, const char* my_file_name)
    {
    char* buffer = nullptr;
    FILE* native = fopen(my_file_name, "rb");

    if (native == NULL)
        {
        return (int)ErrorsOfSPU::ERROR_FILE;
        }

    int* codeArray = ByteCtor(native, my_file_name);
       // this is krivo!!!
        // kill!
         // this is krivo!!!

          // kill!
           // the zhirnaya funkcija
    spu->native       = native;
    spu->codeArray    = codeArray;
    spu->position     = 0;
    spu->my_file_name = my_file_name;

    STACK_CONSTRUCT(stk, 20);

    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorDtor(struct Processor* spu)
    {
    if ((spu->native) != stdin)
        {
        fclose(spu->native);
        }

    spu->my_file_name = "";
    spu->native       = nullptr;
    spu->position     = 0;

    StackDtor(&(spu->stk));
    ByteDtor(spu->codeArray);

    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorPush(struct Processor* spu)
    {
    int element = POISON;
    element = (elem_t) spu->codeArray[spu->position++];

    StackPush(&(spu->stk), element * COEFFICIENT);
    printf(PRINTFELEM "\n", element);

    PROCESSOR_VERIFY(spu);
    return (int)ErrorsOfSPU::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorPushR (struct Processor* spu)
    {
    int code = 0;

    code = (elem_t) spu->codeArray[spu->position++];

    StackPush(&(spu->stk), Variables(spu, code));

    return (int)ErrorsOfSPU::NO_ERROR;
    }

//-----------------------------------------------------------------------------

elem_t Variables (struct Processor* spu, int code)
    {
    switch (code)
        {
        case ((int)Registers::CRAX):
            return spu->rax;
        case ((int)Registers::CRBX):
            return spu->rbx;
        case ((int)Registers::CRCX):
            return spu->rcx;
        case ((int)Registers::CRDX):
            return spu->rdx;
        default:
            fprintf(stderr, "%d - unknown command code, are you confident in your actions?\n", code);
            assert(false);
            return 1;
        }
    }

//-----------------------------------------------------------------------------

int ProcessorPop(struct Processor* spu, int code)
    {
    elem_t reg = spu->codeArray[spu->position++];
    elem_t value = POISON;

    StackPop(&(spu->stk), &value);

    switch(reg)
        {
        case ((int)Registers::CRAX):
            spu->rax = value;
            break;
        case ((int)Registers::CRBX):
            spu->rbx = value;
            break;
        case ((int)Registers::CRCX):
            spu->rcx = value;
            break;
        case ((int)Registers::CRDX):
            spu->rdx = value;
            break;
        }

    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcessorOk(FILE* fp, struct Processor* spu)
    {
    VERIFY(&(spu->stk));
    if (spu == nullptr)
        {
        fprintf(fp, "You have problem in initialization of spu\n");
        return (int)ErrorsOfSPU::ERROR_SPU;
        }
    if (spu->native == NULL)
        {
        fprintf(fp, "You have problem in initialization of native file\n");
        return (int)ErrorsOfSPU::ERROR_FILE;
        }
    return (int)ErrorsOfSPU::NO_ERROR;
    }

//-----------------------------------------------------------------------------

int ProcesserDump(FILE* fp, struct Processor* spu, const char *file, int line, const char *function)
    {
    assert(spu);
    assert(spu->codeArray);
    assert(file);

    STACK_DUMP(&(spu->stk));
    fprintf(fp, "---------------------------------------------------\n");
    fprintf(fp, "START\n");

    fprintf(fp, "Processor address [%p]\n\n"
                "File name:    \"%s\"\n"
                "Pointer to a binary file: [%p]\n"
                "Byte buffer codeArray:  [%zu]\n"
                "Position:     [%d]\n"
                "REGISTERS:\n\n",
                spu, spu->my_file_name, spu->native, spu->codeArray, spu->position);

    PrintRegisters(fp, spu);

    fprintf(fp, "=====================================================\n");

    return (int)ErrorsOfSPU::NO_ERROR;
    }


//-----------------------------------------------------------------------------

static void PrintRegisters(FILE* fp, struct Processor* spu)
    {
    assert(fp);
    assert(spu);

    fprintf(fp, "%s > " PRINTFELEM "\n"
                "%s > " PRINTFELEM "\n"
                "%s > " PRINTFELEM "\n"
                "%s > " PRINTFELEM "\n",
                RAX, spu->rax,
                RBX, spu->rbx,
                RCX, spu->rcx,
                RDX, spu->rdx);
    }
//-----------------------------------------------------------------------------

void BinaryPrintout(struct Processor* spu, int position)
    {
    FILE* output = fopen("binary_code1.bin", "wb");
    double* codeArray = (double*) calloc(position, sizeof(codeArray[1]));
    for (int i = 0; i < position; i++)
        {
        fprintf(output, "%d - %08X\n", (spu->codeArray)[i], (spu->codeArray)[i]);
        }
    }

//-----------------------------------------------------------------------------

static int* ByteCtor(FILE* native, const char* my_file_name)
    {
    assert(native);
    assert(my_file_name);

    int len = 0;
    size_t check = fread(&len, sizeof(int), 1, native);
    if (check == 0)
        {
        fprintf(stderr, "you have problems with reading\n");
        return nullptr;
        }

    int* codeArray = (int*) calloc(len, sizeof(int));
    if (codeArray == nullptr)
        {
        return nullptr;
        }

    size_t read = fread(codeArray, sizeof(int), len, native);
    if (read == 0)
        {
        fprintf(stderr, "you have problems with reading\n");
        return nullptr;
        }

    return codeArray;
    }

//-----------------------------------------------------------------------------------------------------

void ByteDtor(int* codeArray)
    {
    assert(codeArray);

    free(codeArray);
    }
