#include "input.h"

void input(char *path, char symbol[], char alease[])
{
    fgets(path, 260, stdin);
    printf("symbol: ");
    gets(symbol);
    printf("alease: ");
    gets(alease);
    return;
}

