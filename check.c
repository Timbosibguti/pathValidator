#include "check.h"

// public:
int parsToSymbol(char string[], int fromSymbolNum, char toSymbol, char returningPart[])
{
    char currentSymbol = 255;
    int _fromSymbolNum = fromSymbolNum;

    while(currentSymbol != toSymbol)
    {
        currentSymbol = string[fromSymbolNum];
        returningPart[abs(fromSymbolNum - _fromSymbolNum)] = currentSymbol;
        fromSymbolNum++;
        if(currentSymbol == '\0')
        {
            return -1;
        }
    }
    returningPart[abs(fromSymbolNum- _fromSymbolNum)-1] = '\0';
    return fromSymbolNum;
}

void parsToPos(char string[], int from, int to,char returningPart[])
{
    int i = 0;
    for(i = from; i < from+to; i++)
    {
        returningPart[abs(i - from)] = string[i];
    }
    returningPart[abs(i - from)] = '\0';
}

void substructStr(int start, char str[], char substractedStr[])
{
    char currentChar = 255;
    int _start = start;

    while(currentChar != '\0')
    {
        substractedStr[abs(_start - start)] = str[start];
        currentChar = str[start];
        start++;
    }
}

int slen(char str[])
{
    int i = 0;
    char c = 255;
    while(c != '\0'){
        c = str[i];
        i++;
    }
    return i;
}
// /public
// private:
int protocolValidation(char result)
{
    int valid = 0;
    switch (charSumm(result))
    {
    case HTTP:
    case _HTTP:
    case FTP:
    case _FTP:
    case SMB:
    case _SMB:
    case RSYNK:
    case _RSYNK:
        valid = 1;
        break;
    default:
        valid = 0;
        break;
    }
    return valid;
}

int cheking(char str[])
{
    char result[32],
            substractedPath[255];
    int valid = 0;
    int start = 0;

    start = parsToSymbol(str, 0, ':', result);
    // check a protocol
    valid = protocolValidation(result);
    if( !valid ){
        return adressError(str, start, "unexpected protocol");
    }
    // /check a protocol
    substructStr(start, str, substractedPath);
    // check
    parsToPos(str, start, 2, result);
    start += 2;
    if (charSumm(result) != charSumm("//")){
//    if (result[0] != '/' && result[1] != '/') {
        errno = EFAULT;
        perror("sintax error");
    }///todo else
    //-----
    char cc = 255,
         c = 255;
    int i = start,
        j = 0;

    while(cc != '\0')
    {
        cc = substractedPath[0];
        int _start = start;
        start = parsToSymbol(str, start, '/', result);

        for(j = 0; j < slen(result); ++j) {
            c = result[j];
            char error[128] = {'\0'};
            switch((int)c)
            {
            case (int)'\\':
            case (int)'*':
            case (int)':':
            case (int)'?':
            case (int)'\"':
            case (int)'<':
            case (int)'>':
            case (int)'|':
                return adressError(str, _start+j, "unexpected char");
            default:
                break;
            }
        }
        substructStr(start, str, substractedPath);
        i++;
    }
}

int charSumm(char str[])
{
    int i = 0,
            summ = 0;
    char c = 255;
    while (c != '\0') {
        c = str[i];
        summ += (int)c;
        i++;
    }
    return summ;
}


//int HTTP = charSumm("http");
