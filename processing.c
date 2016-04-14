#include "processing.h"

int processing(char path[], char symbol, char alease, char result[])
{
    char c = 255;
    int i = 0, count = 0;
    while(c != '\0'){
        c = path[i];
        if( c == symbol ){
            c = alease;
            count++;
        }
        result[i] = c;
        i++;
    }
    if( !count )
        return 1;

    return 0;
}

