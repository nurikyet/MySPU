#ifndef TOTALFILE_H_INCLUDED
#define TOTALFILE_H_INCLUDED

static const char* PUSH         = "push";
static const char* PUSH_R       = "push_r";
static const char* POP          = "pop";
static const char* ADD          = "add";
static const char* MUL          = "mul";
static const char* SQRT         = "sqrt";
static const char* SIN          = "sin";
static const char* COS          = "cos";
static const char* IN           = "in";
static const char* SUB          = "sub";
static const char* OUT          = "out";
static const char* DIV          = "div";
static const char* HLT          = "hlt";
static const char* TG           = "tg";
static const char* CTG          = "ctg";
static const char* POW          = "pow";

static const char* BOTAY        = "botay";
static const char* SLEEP        = "sleep";
static const char* DEADLINE     = "deadline";

static const char* CAT          = "cat";
static const char* DOG          = "dog";

static const char* RAX          = "rax";
static const char* RBX          = "rbx";
static const char* RCX          = "rcx";
static const char* RDX          = "rdx";

enum class Commands
    {
    CHLT      = -1,
    CPUSH     =  1,
    CADD      =  2,
    CMUL      =  3,
    CSQRT     =  4,
    CSIN      =  5,
    CCOS      =  6,
    CIN       =  7,
    CSUB      =  8,
    COUT      =  9,
    CDIV      =  10,
    CPOP      =  11,
    CTG       =  12,
    CCTG      =  13,
    CPOW      =  14,
    CDOG      =  15,
    CCAT      =  16,
    CSLEEP    =  17,
    CBOTAY    =  18,
    CDEADLINE =  19,
    CPUSH_R   =  33
    };

enum class Registers
    {
    CRAX = 0,
    CRBX = 1,
    CRCX = 2,
    CRDX = 3
    };

enum class ErrorsOfSPU
    {
    NO_ERROR              = 0,
    ERROR_SIGNATURE       = 1 << 8,
    ERROR_VERSION         = 1 << 9,
    ERROR_MEMMORY         = 1 << 10,
    ERROR_UNKNOWN_COMMAND = 1 << 11,
    ERROR_FILE            = 1 << 12,
    ERROR_SPU             = 1 << 13
    };

#endif // TOTALFILE_H_INCLUDED
