#ifndef SPU_H_INCLUDED
#define SPU_H_INCLUDED

#include "..\Stack.h"
#include "ErrorsOfSPU.h"

#define PROCESSOR_DUMP(spu) ProcessorDump(LOG_FILE, spu, __FILE__, __LINE__,  __func__)

#define PROCESSOR_VERIFY(spu) {int error = ProcessorOk(LOG_FILE, spu);              \
                               if (error != 0)                                      \
                                   {                                                \
                                   PrintError(LOG_FILE, error);                     \
                                   PrintErrorsOfSPU(LOG_FILE, result);              \
                                   PROCESSOR_DUMP(spu);                             \
                                   return error;                                    \
                                   }                                                \
                               }

static void PrintRegisters(FILE* fp, struct Processor* spu);

void BinaryPrintout(struct Processor* spu, int position);
void ByteDtor(int* codeArray);

elem_t Variables (struct Processor* spu, int code);

static int* ByteCtor(FILE* native, const char* my_file_name);

int CommandOptions(char* line);
int Compare(struct Processor* spu);
int RegistreOptions(struct Processor*spu);

int ProcessorCtor(struct processor* spu, const char* my_file_name);
int ProcessorDtor(struct Processor* spu);
int ProcessorPush(struct Processor* spu);
int ProcessorPushR(struct Processor* spu);
int ProcessorPop(struct Processor* spu, int code);
int ProcessorDump(FILE* fp, struct Processor* spu, const char *file, int line, const char *function);
int ProcessorOk(struct Processor* spu);

#endif // SPU_H_INCLUDED
