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
    returningPart[abs(fromSymbolNum - _fromSymbolNum)-1] = '\0';
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
int protocolValidation(char protName[])
{
    int valid = 0;
    switch (charSumm(protName))
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

int symbolValidation(char word[])
{
    int i, size = slen(word);
    for(i = 0; i < size; ++i) {
        char c = word[i];
        switch((int)c)
        {
        case (int)'\\':
        case (int)'\"':
        case (int)'\'':
        case (int)'*':
        case (int)'^':
        case (int)':':
        case (int)'?':
        case (int)'<':
        case (int)'>':
        case (int)'|':
            return i+1;
        default:
            break;
        }
    }
    return 0;
}

int pathValidation(char url[], char substractedPath[], int start)
{
    int valid = 0;
    char result[240] = {'\0'};
    char cc = 255;

    while(cc != '\0'){
        cc = substractedPath[0];
        int _start = start;
        start = parsToSymbol(url, start, '/', result);
        if((valid = symbolValidation(result))){
            return adressError(url, _start-1 + valid, "unexpected symbol");
        }
        substructStr(start, url, substractedPath);
    }

    return valid;
}

int validationOfIP(char ip[], int pos, char url[])
{
    char c = 255,
         octet[4];
    int i = 0,
        dotPos = 0;
    int _start = pos;
    while(c != '\0'){
        c = ip[i];
        if( (c > 'A' && c < 'Z') || (c > 'a' && c < 'z') )
            return adressError(url, _start+1, "undexpected char in octet,\n\t the octet most consist of numbers in range from 0 to 255");

        if(c != '.' && c != '\0')
            octet[i - dotPos] = c;
        else{
            if(atoi(octet) > 255 || atoi(octet) < 0)
                return adressError(url, _start+dotPos, "An octet most consist of numbers in range from 0 to 255");

            dotPos = i+1;
            octet[0] = '\0';
            octet[1] = '\0';
            octet[2] = '\0';
            octet[3] = '\0';
        }
        i++;
    }
}

int cheking(char url[])
{
    char result[32],
         substractedPath[255];
    int valid = 0;
    int start = 0;

    start = parsToSymbol(url, 0, ':', result);
    // check a protocol
    valid = protocolValidation(result);
    if( !valid ){
        return adressError(url, 0, "unexpected protocol");
    }
    // /check a protocol

    substructStr(start, url, substractedPath);
    parsToPos(url, start, 2, result);
    start += 2;
    if (charSumm(result) != charSumm("//")){
        errno = EFAULT;
        perror("sintax error, must be [protocol]://");
    }

    start = parsToSymbol(url, start, '/', result);
    validationOfIP(result, start, url);
    substructStr(start, url, substractedPath);

    return pathValidation(url, substractedPath, start);
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

