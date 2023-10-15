#include <stdio.h>

#include "Assembler.h"

int main()
    {
    FILE* InputFile = fopen("test.txt", "r");
    FILE* OutputFile = fopen("machine_code.txt", "w");

    Assembler(InputFile, OutputFile);

    fclose(InputFile);
    fclose(OutputFile);

    return 0;
    }
