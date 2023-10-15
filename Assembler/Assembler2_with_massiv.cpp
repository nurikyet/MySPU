#include <strings.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Assembler.h"
#include "..\Types.h"
#include "..\TotalFile.h"

//-----------------------------------------------------------------------------

int Assembler(FILE* InputFile, FILE* OutputFile)
    {

    assert(InputFile);
    assert(OutputFile);

    int* codeArray = (int*)calloc(MAX_LEN_OF_ARRAY, sizeof(int));
    if (codeArray == nullptr)
        {
        return (int)ErrorsOfSPU::ERROR_MEMMORY;
        }
    int position = 0;

    int version = 0;
    fscanf(InputFile, "%d", &version);

    char signature[MAX_LEN_OF_LINE] = "";
    fscanf(InputFile, "%s", &signature);

    if (version != MY_VERSION)
        {
        fprintf(stderr, "%d - wrong program version\n", version);
        return (int)ErrorsOfSPU::ERROR_VERSION;
        }

    else if (strcmp(signature, MY_SIGNATURE) != 0)
        {
        fprintf(stderr, "%s - wrong signature version\n", signature);
        return (int)ErrorsOfSPU::ERROR_SIGNATURE;
        }

    char line[MAX_LEN_OF_LINE] = "";

    while(fscanf(InputFile, "%s", line) != 0)
        {
        if (strcmp(line, HLT) == 0)
            {
            codeArray[position++] = (int) Commands::CHLT;
            break;
            }
        else if (strcmp(line, OUT) == 0)
            {
            codeArray[position++] = (int) Commands::COUT;
            }
        else if (strcmp(line, PUSH) == 0)
            {
            codeArray[position++] = (int) Commands::CPUSH;

            elem_t element = POISON;
            fscanf(InputFile, "%d", &element);
            codeArray[position++] = element;
            }
        else if (strcmp(line, PUSH_R) == 0)
            {
            codeArray[position++] = (int) Commands::CPUSH_R;
            char regis[MAX_LEN_OF_LINE] = "";
            fscanf(InputFile, "%s", regis);
            if (strcmp(regis, RAX) == 0)
                {
                codeArray[position++] = ((int) Registers::CRAX);
                }
            else if (strcmp(regis, RBX) == 0)
                {
                codeArray[position++] = ((int) Registers::CRBX);
                }
            else if (strcmp(regis, RCX) == 0)
                {
                codeArray[position++] = ((int) Registers::CRCX);
                }
            }
        else if (strcmp(line, POP) == 0)
            {
            codeArray[position++] = ((int) Commands::CPOP);

            char reg[MAX_LEN_OF_LINE] = "";
            fscanf(InputFile, "%s", reg);
            if (strcmp(reg, RAX) == 0)
                {
                codeArray[position++] = ((int) Registers::CRAX);
                }
            else if (strcmp(reg, RBX) == 0)
                {
                codeArray[position++] = ((int) Registers::CRBX);
                }
            else if (strcmp(reg, RCX) == 0)
                {
                codeArray[position++] = ((int) Registers::CRCX);
                }
            }
        else if (strcmp(line, ADD) == 0)
            {
            codeArray[position++] = (int) Commands::CADD;
            }
        else if (strcmp(line, SUB) == 0)
            {
            codeArray[position++] = (int) Commands::CSUB;
            }
        else if (strcmp(line, MUL) == 0)
            {
            codeArray[position++] = (int) Commands::CMUL;
            }
        else if (strcmp(line, DIV) == 0)
            {
            codeArray[position++] = (int) Commands::CDIV;
            }
        else if (strcmp(line, SQRT) == 0)
            {
            codeArray[position++] = (int) Commands::CSQRT;
            }
        else if (strcmp(line, COS) == 0)
            {
            codeArray[position++] = (int) Commands::CCOS;
            }
        else if (strcmp(line, SIN) == 0)
            {
            codeArray[position++] = (int) Commands::CSIN;
            }
        else if (strcmp(line, IN) == 0)
            {
            codeArray[position++] = (int) Commands::CIN;
            }
        else if (strcmp(line, POW) == 0)
            {
            codeArray[position++] = (int) Commands::CPOW;
            }
        else if (strcmp(line, CAT) == 0)
            {
            codeArray[position++] = (int) Commands::CCAT;
            }
        else if (strcmp(line, DOG) == 0)
            {
            codeArray[position++] = (int) Commands::CDOG;
            }
        else if (strcmp(line, SLEEP) == 0)
            {
            codeArray[position++] = (int) Commands::CSLEEP;
            }
        else if (strcmp(line, BOTAY) == 0)
            {
            codeArray[position++] = (int) Commands::CBOTAY;
            }
        else if (strcmp(line, DEADLINE) == 0)
            {
            codeArray[position++] = (int) Commands::CDEADLINE;
            }
        else if (strcmp(line, TG) == 0)
            {
            codeArray[position++] = (int) Commands::CTG;
            }
        else if (strcmp(line, CTG) == 0)
            {
            codeArray[position++] = (int) Commands::CCTG;
            }
        else
            {
            return (int)ErrorsOfSPU::ERROR_UNKNOWN_COMMAND;
            }
        }

    MassivOut(OutputFile, codeArray, position);

    BinaryRecordind(codeArray, position);
    return (int)ErrorsOfSPU::NO_ERROR;
    }

//-----------------------------------------------------------------------------

void MassivOut(FILE* OutputFile, int* codeArray, int len)
    {
    assert(OutputFile);

    for (int i = 0; i < len; i++)
        {
        fprintf(OutputFile, "%d\n", codeArray[i]);
                //fprintf(stderr, "%d\n", codeArray[i]);
        }
    free(codeArray);
    }

//-----------------------------------------------------------------------------

int BinaryRecordind(int* codeArray, int position)
    {
    FILE* file = fopen("code.bin", "wb");

    if (file == NULL)
        {
        printf("I can not open the file\n");
        return (int)ErrorsOfSPU::ERROR_FILE;
        }
    fwrite(&position, sizeof(int), 1, file);
    size_t elements_written = fwrite(codeArray, sizeof(int), position, file);

    if (elements_written != position)
        {
        printf("Error in recording\n");
        fclose(file);
        return 1;
    }

    fclose(file);
    /*
    file = fopen("code.bin", "rb");

    fprintf (LOG_FILE, "From binary code\n");
    for (int i = 0; i < position; i++)
        {
        fprintf(LOG_FILE, "%d - %08X\n", i, codeArry[i]);
        }

    fclose(file);
    */
    return 0;
}

//-----------------------------------------------------------------------------


