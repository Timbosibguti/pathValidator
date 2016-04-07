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

void input(char path[])
{
    fgets(path, 260, stdin);
}


int main(void)
{
    char path[] = "ftp://192.167.1.7/sup*er/duper",
         result[32];

    cheking(path);
    return 0;
}

