#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

#include "Stack.h"

const int COEFFICIENT = 100;

void ProcessorDog();
void ProcessorCat();

int ProcessorPow(struct Processor* spu);
int ProcessorAdd(struct Processor* spu);
int ProcessorSub(struct Processor* spu);
int ProcessorOut(struct Processor* spu);
int ProcessorIn(struct  Processor* spu);
int ProcessorDiv(struct Processor* spu);
int ProcessorMul(struct Processor* spu);
int ProcessorCos(struct Processor* spu);
int ProcessorSin(struct Processor* spu);
int ProcessorSqrt(struct Processor* spu);
int ProcessorTg(struct Processor* spu);
int ProcessorCtg(struct Processor* spu);
int ProcessorPow(struct Processor* spu);

#endif // COMMANDS_H_INCLUDED
