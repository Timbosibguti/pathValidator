#include "errorloger.h"

int errorLog(int errorType)
{
    errno = errorType;
    perror(error);
    return errorType;
}

void strErrPointing(int errPos)
{
    int i = 0;
    char errPointer[260];
    for (int i = 0; i < errPos; ++i) {
        sprintf(errPointer, "-");
    }
    sprintf(errPointer, "^\n");
}

int strError(int errorType, char str, int errPos)
{
    errno = errorType;

    strErrPointing(errPos);

    sprintf(errorMsg, "String sintax error!"
                   "\n%s\n%s", path, result);
}

