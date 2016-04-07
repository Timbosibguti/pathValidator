#ifndef ERRORLOGER_H
#define ERRORLOGER_H
#include <stdio.h>
#include <errno.h>

char errorMsg[255];
int errorLog(int errorType);
int strError(int errorType, char str, int errPos);
int adressError(int errorType, char adress, int errPos);
//------------------------------
void strErrPointing(int errPos);
#endif // ERRORLOGER_H
