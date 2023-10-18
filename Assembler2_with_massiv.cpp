#include <strings.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Assembler.h"
#include "..\Types.h"
#include "..\TotalFile.h"


#define DEF_CMD(name, num, have_arg, code)                              \
    if (strcmp(line, #name) == 0)                                       \
        {                                                               \
        codeArray[position++] = (int) Commands::C##name;                \
                                                                \
        if (have_arg)                                                   \
            {                                                           \
            elem_t element = POISON;                                    \
            char regis[MAX_LEN_OF_LINE] = "";                           \
            if (fscanf(InputFile, "%d", &element))                      \
                {                                                       \
                codeArray[position++] = element;                        \
                }                                                       \
            else if (fscanf(InputFile, "%s", regis))                    \
                {                                                       \
                if (strcmp(regis, RAX) == 0)                            \
                    {                                                   \
                    codeArray[position++] = ((int) Registers::CRAX);    \
                    }                                                   \
                else if (strcmp(regis, RBX) == 0)                       \
                    {                                                   \
                    codeArray[position++] = ((int) Registers::CRBX);    \
                    }                                                   \
                else if (strcmp(regis, RCX) == 0)                       \
                    {                                                   \
                    codeArray[position++] = ((int) Registers::CRCX);    \
                    }                                                   \
                }                                                       \
            }                                                           \
        }                                                               \
    else

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
        #include "..\MyCommands.h"
        /*else*/ return (int)ErrorsOfSPU::ERROR_UNKNOWN_COMMAND;
        }
    #undef DEF_CMD

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
        }
    free(codeArray);
    }

//-----------------------------------------------------------------------------

int BinaryRecord(int* codeArray, int position)
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

    fprintf (LOG_FILE, "\n<<<From binary code>>>\n");
    for (int i = 0; i < position; i++)
        {
        fprintf(LOG_FILE, "%d - %08X\n", i, codeArry[i]);
        }

    fclose(file);
    */
    return 0;
}

//-----------------------------------------------------------------------------

