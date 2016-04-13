#include "processing.h"

int processing(char path[], char symbol, char alease, char result[])
{
    char c = 255;
    int i = 0;
    while(c != symbol){
        c = path[i];
        result[i] = c;
        i++;
    }
    result[i] = alease;
    i++;
    while(c != '\0'){
        c = path[i];
        result[i] = c;
        i++;
    }
}

