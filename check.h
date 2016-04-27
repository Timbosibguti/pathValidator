#ifndef CHECK_H
#define CHECK_H
#include "errorloger.h"
/// TODO CHECK
/// get str for check
/// parsing to parts
/// * checkin for valide protocol///


// const items
//// protocols
#define    HTTP     (int)'h' + 2*(int)'t' + (int)'p'
#define    FTP      (int)'f' + (int)'t' + (int)'p'
#define    RSYNC    (int)'r' + (int)'s' + (int)'y' + (int)'n' + (int)'c'
#define    SMB      (int)'s' + (int)'m' + (int)'b'
#define    _HTTP    (int)'H' + 2*(int)'T' + (int)'P'
#define    _FTP     (int)'F' + (int)'T' + (int)'P'
#define    _RSYNC   (int)'R' + (int)'S' + (int)'Y' + (int)'N' + (int)'C'
#define    _SMB     (int)'S' + (int)'M' + (int)'B'
//// /protocols

// /const items

int cheking(char url[]);


int parsToSymbol(char string[], int fromSymbolNum, char toSymbol, char returningPart[]);
void parsToPos(char string[], int from, int to,char returningPart[]);
void substructStr(int start, char str[], char substractedStr[]);
int slen(char str[]);

int charSumm(char str[]);



#endif // CHECK_H
