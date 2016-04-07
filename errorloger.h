#ifndef ERRORLOGER_H
#define ERRORLOGER_H
#include <stdio.h>
#include <errno.h>

char errorMsg[255];
int errorLog(int errorType);
int strError(int errorType, char str[], int errPos, char strType[], char errMsg[]);
int adressError(char adres[], int errPos, char errMsg[]);
//------------------------------
void strErrPointing(int errPos, char _errPointer[]);
#endif // ERRORLOGER_H
