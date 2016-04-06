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

int parsToSymbol(char string[],
                  int fromSymbolNum,
                  char toSymbol,
                  char returningPart[])
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
    returningPart[fromSymbolNum] = '\0';
    return fromSymbolNum;
}

int main(void)
{
    char path[260] = {'\0'},
         result[32];
    input(path);

    int start = 0, _start = 0;
    start = parsToSymbol(path, 0, ':', result);

//    char parsedStr[64][255];
    char substractedPath[255];

    char currentChar = 255;
    _start = start;

    while(currentChar != '\0')
    {
        substractedPath[abs(_start - start)] = path[start];
        currentChar = path[start];
        start++;
    }

    printf("path: %s\n result: %s"
           "\n endNum: %i\n substractionPath: %s\n",
           path, result, start, substractedPath);
    return 0;
}

