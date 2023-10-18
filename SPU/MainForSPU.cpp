#include <stdio.h>
#include <stdlib.h>

//#include "..\Stack.h"
#include "logfile.h"
//#include "..\Types.h"
//#include "..\Hash.h"
#include "SPU.h"

int main(const int argc, const char* argv[])
{
    OpenLog(argv[0]);

    struct Processor spu = {};

    if (argc == 1)
        ProcessorCtor(&spu, argv[1]);
    else
        ProcessorCtor(&spu, argv[1]);

    Compare(&spu);

    PROCESSOR_DUMP(&spu);

    ProcessorDtor(&spu);

    return 0;
}
