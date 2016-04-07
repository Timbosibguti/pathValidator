#include "errorloger.h"

int errorLog(int errorType)
{
    errno = errorType;
    perror("error");
    return errorType;
}

void strErrPointing(int errPos, char errPointer[])
{
    int i = 0;
    for (i = 0; i < errPos; ++i) {
        errPointer[i] = '-';
    }
    errPointer[i] = '^';
    errPointer[i+1] = '\0';
}

int strError(int errorType, char str[], int errPos, char strType[], char errMsg[])
{
    errno = errorType;
    char errPointer[260];
    strErrPointing(errPos, errPointer);

    sprintf(errorMsg, "%s sintax error: %s"
                   "\n%s\n%s\n", strType, errMsg, str, errPointer);
    perror(errorMsg);
    return errno;
}

int adressError(char adres[], int errPos, char errMsg[])
{
    strError(EFAULT, adres, errPos, "URL", errMsg);

    return errno;
}



