#ifndef ASSEMBLER_H_INCLUDED
#define ASSEMBLER_H_INCLUDED

const int MAX_LEN_OF_ARRAY = 100;
const int MY_VERSION = 1;
const int MAX_LEN_OF_LINE = 256;
const int NUMBER_OF_LABELS = 10;

static const char* MY_SIGNATURE = "0401";
static const int POISON = -777;

int Assembler(FILE* InputFile, FILE* OutputFile);
int BinaryRecord(int* codeArray, int position);
int ProcessLabel(int* labels, char* line, int position);

void MassivOut(FILE* OutputFile, int* codeArray, int len);

#endif // ASSEMBLER_H_INCLUDED
