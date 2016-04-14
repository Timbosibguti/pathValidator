//#pragma once


//#include <math.h>
#include "check.h"
#include "processing.h"
#include "output.h"

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


int main(void)
{
    char path[260],
         symbol[3], alease[3],
         result[260];

    input(path, symbol, alease);

    cheking(path);
    processing(path, symbol[0], alease[0], result);
    output(result);
    return 0;
}

