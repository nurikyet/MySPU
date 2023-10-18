DEF_CMD(HLT, -1, 0,
    {
    return (int)ErrorsOfSPU::NO_ERROR;
    })

DEF_CMD(PUSH, 1, 1,
    {
    ProcessorPush(spu);
    })

DEF_CMD(ADD, 2, 0,
    {
    ProcessorAdd(spu);
    })

DEF_CMD(MUL, 3, 0,
    {
    ProcessorMul(spu);
    })

DEF_CMD(SQRT, 4, 0,
    {
    ProcessorSqrt(spu);
    })

DEF_CMD(SIN, 5, 0,
    {
    ProcessorSin(spu);

    })

DEF_CMD(COS, 6, 0,
    {
    ProcessorCos(spu);
    })

DEF_CMD(IN, 7, 0,
    {
    ProcessorIn(spu);
    })

DEF_CMD(SUB, 8, 0,
    {
    ProcessorSub(spu);
    })

DEF_CMD(OUT, 9, 0,
    {
    ProcessorOut(spu);
    })

DEF_CMD(DIV, 10, 0,
    {
    ProcessorDiv(spu);
    })

DEF_CMD(POP, 11, 1,
    {
    ProcessorPop(spu);
    })

DEF_CMD(TG, 12, 0,
    {
    ProcessorTg(spu);
    })

DEF_CMD(CTG, 13, 0,
    {
    ProcessorCtg(spu);
    })

DEF_CMD(POW, 14, 0,
    {
    ProcessorPow(spu);
    })

DEF_CMD(DOG, 15, 0,
    {
    ProcessorDog();
    })

DEF_CMD(CAT, 16, 0,
    {
    ProcessorCat();
    })

DEF_CMD(SLEEP, 17, 0,
    {
    ProcessorSleep();
    })

DEF_CMD(BOTAY, 18, 0,
    {
    ProcessorBotay();
    })

DEF_CMD(DEADLINE, 19, 0,
    {
    ProcessorDeadline();
    })

DEF_CMD(PUSH_R, 20, 1,
    {
    ProcessorPushR(spu);
    })
