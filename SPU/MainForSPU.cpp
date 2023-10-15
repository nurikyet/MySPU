#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "../common/log_funcs.h"
#include "../common/types.h"
#include "../common/hash.h"
#include "SPU.h"

int main(const int argc, const char* argv[])
{
    OpenLogFile(argv[0]);

    struct Processor spu = {};

    if (argc == 1)
        ProcessorCtor(&spu);
    else
        ProcessorCtor(&spu, argv[1]);

    Compare(&spu);

    PROCESSOR_DUMP(&spu);

    ProcessorDtor(&spu);

    return 0;
}
