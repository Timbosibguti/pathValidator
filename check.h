#ifndef CHECK_H
#define CHECK_H
#include "errorloger.h"
/// TODO CHECK
/// get str for check
/// parsing to parts
/// * checkin for valide protocol


int cheking(char str[]);


int parsToSymbol(char string[], int fromSymbolNum, char toSymbol, char returningPart[]);
void parsToPos(char string[], int from, int to,char returningPart[]);
void substructStr(int start, char str[], char substractedStr[]);
int slen(char str[]);

#endif // CHECK_H
