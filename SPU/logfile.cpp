#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "logfile.h"
#include "..\Types.h"
#include "Stack.h"

FILE* LOG_FILE = stderr;
static const char* EXTENSION = ".log";

int OpenLog(const char* my_file)
    {
    char* file_name = (char*) calloc(strlen(my_file) + strlen(EXTENSION) + 1, 1);
    if (file_name == NULL)
        {
        printf("Too long file name\n");
        return (int)Error::ERROR_MEMORY;
        }
    strncpy(file_name, my_file, MAX_LEN);
    LOG_FILE = fopen(strncat(file_name, EXTENSION, MAX_LEN), "a");

    time_t now = 0;
    time(&now);
    fprintf(LOG_FILE, "------------------------------START AT %s--------------------------------\n", ctime(&now));

    IF_CANARY(fprintf(LOG_FILE, "Work with CANARY\n");)

    IF_HASH(fprintf(LOG_FILE, "Work with HASH\n");)

    free(file_name);
    atexit(CloseLog);
    return 0;
    }

//-----------------------------------------------------------------------------

void CloseLog()
    {
    fprintf(LOG_FILE, "------------------------The work is completed----------------------------\n");
    fclose(LOG_FILE);
    }

