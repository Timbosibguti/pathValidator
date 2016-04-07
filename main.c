#include <stdio.h>
#include <math.h>


/*
 * TODO List
 * обеспечить ввод данных и организовать как функцию \made
 *
 * разобрать строку на составляющие
 * * протокол
 * * * отдельной функцией проверить валидность
 * * ip-адрес
 * * * также проверить на валидность
 * * затем путь
 * * * проврить на наличие запрещенных символов
 * * * путь нужно вернуть для замены символов
 */

void input(char path[])
{
    fgets(path, 260, stdin);
}

int parsToSymbol(char string[], int fromSymbolNum,
                 char toSymbol, char returningPart[])
{
    char currentSymbol = 255;
    while(currentSymbol != toSymbol)
    {
        currentSymbol = string[fromSymbolNum];
        returningPart[fromSymbolNum] = currentSymbol;
        printf("%i %s\n", fromSymbolNum, returningPart);
        fromSymbolNum++;
        if(currentSymbol == '\0')
        {
            return -1;
        }
    }
    returningPart[fromSymbolNum-1] = '\0';
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

void substructPath(int start, char path[], char substractedPath[])
{
    char currentChar = 255;
    int _start = start;

    while(currentChar != '\0')
    {
        substractedPath[abs(_start - start)] = path[start];
        currentChar = path[start];
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

int main(void)
{
    char path[] = "http://192.167.1.7/super/duper",
         result[32];
 //   input(path);
//    path = "http://192.167.1.7/super/duper";

    int start = 0;
    start = parsToSymbol(path, 0, ':', result);
    char substractedPath[255];

    substructPath(start, path, substractedPath);

    // check
    int valid = 0;
    parsToPos(path, start, 2, result);
    start += 2;
    if (result[0] = '/' && result[1] == '/') {
        valid = 1;
    }
    //-----
    char cc = 255;
    int i = start,
        j = 0;

    while(cc != '\0')
    {
        cc = substractedPath[0];
//        start = parsToSymbol(path, start, '\\', result);
//        if(start != -1){
//            /*
//             * TODO error
//             */
//            printf("path: %s,\n  is invalid", path);
//            return 1;
//        }
        start = parsToSymbol(path, start, '/', result);
        for (int j = 0; j < slen(result); ++j) {

        }
        substructPath(start, path, substractedPath);
        i++;
    }
    // /check
    printf("path: %s\n result: %s"
           "\n endNum: %i\n substractionPath: %s\n",
           path, result, start, substractedPath);
    return 0;
}

