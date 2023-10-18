#include <strings.h>
#include <assert.h>

//-----------------------------------------------------------------------------

int Assembler(FILE* input, FILE* output)
    {
    assert(input);
    assert(output);
    char line[MAX_LEN_OF_LINE] = "";

    int version = 0;
    fscanf(input, "%d", &version);

    char signature[MAX_LEN_OF_LINE] = "";
    fscanf(input, "%s", &signature);

    if (version != MY_VERSION)
        {
        fprintf(stderr, "%d - wrong program version\n", version);
        break;
        }

    else if (strcmp(signature, MY_SIGNATURE) != 0)
        {
        fprintf(stderr, "%s - wrong signature version\n", signature);
        break;
        }

    fprintf(output, "%d\n", version);
    fprintf(output, "%s\n", signature);

    while(true)
        {

        fscanf(input, "%s", line);
        if (strcmp(line, HLT) == 0)
            {
            fprintf(output, "%d", (int)Commands::CHLT);
            break;
            }
        else if (strcmp(line, OUT) == 0)
            {
            fprintf(output, "%d", (int)Commands::COUT);
            }
        else if (strcmp(line, PUSH) == 0)
            {
            fprintf(output, "%d ", (int)Commands::CPUSH);

            elem_t element = POISON;
            fscanf(input, "%lg", &element);
            fprintf(output, "%lg", element);

            }
        else if (strcmp(line, PUSH_R) == 0)
            {
            fprintf(output, "%d ", (int)Commands::CPUSH_R);
            char register[MAX_LEN_OF_LINE] = "";
            if (strcmp(register, RAX) == 0)
                {
                fprintf(output, "%d", (int)Registers::CRAX);
                }
            else if (strcmp(register, RBX) == 0)
                {
                fprintf(output, "%d", (int)Registers::CRBX);
                }
            else if (strcmp(register, RCX) == 0)
                {
                fprintf(output, "%d", (int)Registers::CRCX);
                }
            }
        else if (strcmp(line, POP) == 0)
            {
            fprintf(output, "%s", (int)Commands::CPOP);

            char register[MAX_LEN_OF_LINE] = "";
            if (strcmp(register, RAX) == 0)
                {
                fprintf(output, "%d", (int)Registers::CRAX);
                }
            else if (strcmp(register, RBX) == 0)
                {
                fprintf(output, "%d", (int)Registers::CRBX);
                }
            else if (strcmp(register, RCX) == 0)
                {
                fprintf(output, "%d", (int)Registers::CRCX);
                }
            }
        else if (strcmp(line, ADD) == 0)
            {
            fprintf(output, "%d", (int)Commands::CADD);
            }
        else if (strcmp(line, SUB) == 0)
            {
            fprintf(output, "%d", (int)Commands::CSUB);
            }
        else if (strcmp(line, MUL) == 0)
            {
            fprintf(output, "%d", (int)Commands::CMUL);
            }
        else if (strcmp(line, DIV) == 0)
            {
            fprintf(output, "%d", (int)Commands::CDIV);
            }
        else if (strcmp(line, SQRT) == 0)
            {
            fprintf(output, "%d", (int)Commands::CSQRT);
            }
        else if (strcmp(line, COS) == 0)
            {
            fprintf(output, "%d", (int)Commands::CCOS);
            }
        else if (strcmp(line, SIN) == 0)
            {
            fprintf(output, "%d", (int)Commands::CSIN);
            }
        else:
            {
            return (int)Errors::UNKNOWN_COMMAND;
            }
        fputc('\n', output);
        }
    return (int)Error::NO_ERROR;
    }

//-----------------------------------------------------------------------------


