#pragma once

#include <stdio.h>
#include <math.h>
#include "check.h"

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

void input(char path[], char symbol, char alease)
{
    fgets(path, 260, stdin);
    printf("symbol: ");
    scanf("%c", &symbol);
    //printf("alease: ");
    //gets("%c", &alease);
}


int main(void)
{
    char path[260],
         symbol, alease = '_',
         result[260];

    input(path, &symbol, alease);

    cheking(path);
    processing(path, symbol, alease, result);
    printf("\n---------------\n%s", result);
    return 0;
}

