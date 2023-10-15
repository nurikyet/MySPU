#include <strings.h>
#include <assert.h>

#include "Types.h"
#include "SPU.h"

//-----------------------------------------------------------------------------

void DisAssembler(FILE* input, FILE* output)
    {
    assert(input);
    assert(output);
    int code, value;

    while (fscanf(input, "%d", &code) != EOF)
        {
        switch (code)
            {
            case ((int)Commands::CPUSH):
                elem_t value = 0;
                if (fscanf(input, "%lg", &value) != EOF)
                    {
                    fprintf(output, "push  %lg\n", value);
                    }
                break;
            case ((int)Commands::CPUSH_R):
                int value = 0;
                if (fscanf(input, "%d", &value) != EOF)
                    {
                    switch(value)
                        {
                        case ((int)Registers::CRAX):
                            fprintf(output, "push_r rax\n");
                            break;
                        case ((int)Registers::CRBX):
                            fprintf(output, "push_r rbx\n");
                            break;
                        case ((int)Registers::CRCX):
                            fprintf(output, "push_r rcx\n");
                            break;
                        }
                    }
            case ((int)Commands::CPOP):
                elem_t value = 0;
                if (fscanf(input, "%d", &value) != EOF)
                    {
                    switch(value)
                        {
                        case ((int)Registers::CRAX):
                            fprintf(output, "pop rax\n");
                            break;
                        case ((int)Registers::CRBX):
                            fprintf(output, "pop rbx\n");
                            break;
                        case ((int)Registers::CRCX):
                            fprintf(output, "pop rcx\n");
                            break;
                        }
                    }
            case ((int)Commands::CADD):
                fprintf(output, "add\n");
                break;
            case ((int)Commands::CSUB):
                fprintf(output, "sub\n");
                break;
            case ((int)Commands::CMUL):
                fprintf(output, "mul\n");
                break;
            case ((int)Commands::CDIV):
                fprintf(output, "div\n");
                break;
            case ((int)Commands::CSQRT):
                fprintf(output, "sqrt\n");
                break;
            case ((int)Commands::CSIN):
                fprintf(output, "sin\n");
                break;
            case ((int)Commands::CCOS):
                fprintf(output, "cos\n");
                break;
            case ((int)Commands::COUT):
                fprintf(output, "out\n");
                break;
            case ((int)Commands::CHLT):
                fprintf(output, "hlt\n");
                break;
            default:
                fprintf(output, "unknown\n");
                break;
            }
        }
    }

//-----------------------------------------------------------------------------
