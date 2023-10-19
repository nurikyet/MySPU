#include <stdio.h>
#include <stdlib.h>

//#include "..\Stack.h"
#include "logfile.h"
//#include "..\Types.h"
//#include "..\Hash.h"
#include "SPU.h"

#define ABOBA() printf("\n<<I work in a FILE %s(%d) in %s>>\n", __FILE__, __LINE__, __func__)

int main(const int argc, const char* argv[])
{
    ABOBA();
    OpenLog(argv[0]);
    ABOBA();
    struct Processor spu = {};
    ABOBA();
    ProcessorCtor(&spu, "code2.bin");
    /*
    if (argc == 1)
        ProcessorCtor(&spu, argv[1]);
    else
        ProcessorCtor(&spu, argv[1]);
    */
    ABOBA();
    Compare(&spu);
    ABOBA();
    PROCESSOR_DUMP(&spu);

    ProcessorDtor(&spu);

    return 0;
}
